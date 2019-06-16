import React, { Component } from 'react';
import { FlatList, ScrollView ,Platform, StyleSheet, Text, View } from 'react-native';
import { Grid, List, ListItem, Icon, Row, Col, Button, Card, FormLabel, FormInput, FormValidationMessage } from 'react-native-elements';
import { BleManager, Device, BleError, LogLevel } from "react-native-ble-plx";
import { Base64 } from 'js-base64';


const serviceID = 'FFE0';
const charID = 'FFE1';
const instructions = Platform.select({
  ios: 'Press Cmd+R to reload,\n' + 'Cmd+D or shake for dev menu',
  android:
    'Double tap R on your keyboard to reload,\n' +
    'Shake or press menu button for dev menu',
});

export default class App extends Component {
  constructor(props) {
    super(props)
    this.manager = new BleManager();
    this.peripheralId = '';
    this.state = {
      status : "Not Connected",
      text: [],
      isConnected: false,
      deviceOn: false,
      scanneddevice: null,
      payload: {
        temp: "",
        prediction: "",
      }
    }
  };

  scanBle(){
    this.manager.onStateChange(newState => {
      if (newState != "PoweredOn") return;
      this._log("Started scanning...");
      this.manager.startDeviceScan(
        null,
        {
          allowDuplicates: true
        },
        (error, device) => {
          if (error) {
            this._logError("SCAN", error);
            return;
          }
          if(device.name == ['BLE_IOT_TEMP']){
            this.setState({
              deviceOn: true,
              scanneddevice: device
            })
            this._log("Found device: ", device.name);
            this.manager.stopDeviceScan();
          }
        }
      );
    }, true);
  }

  connectBle(device){
    console.log("Connect btn");
    this.manager.connectToDevice(device.id)
    .then(device=>{
      this._log('Connection success:',device.name);
      this.peripheralId = device.id;
      this.setState({
        isConnected: true,
        status: "WAIT...",
      })
      device.discoverAllServicesAndCharacteristics()
      .then((device) =>{
        device.monitorCharacteristicForService(serviceID, charID, (error, char) => {
          if(error){
            this._log("Error", error);
          }
          if (char){
          var buffer = Base64.decode(char.value);
          var value = JSON.parse(buffer);
          console.log(value);
            this.setState({
              status: `Prediction ${this.predictionDecoder(value.p)}`,
            })
          }
        })
        console.log(device);
      });
    })
  }

  predictionDecoder(value){
    let decoded = "";
    switch (value){
      case 0:
        decoded = "Samsung S9";
        break;
      case 1:
        decoded = "iPhone7s";
        break;
      case 2:
        decoded = "iPhone10";
        break;
      default:
        decoded = "None";
        break;
    }
    return decoded;
  }

  disconnect(){
    this.manager.cancelDeviceConnection(this.peripheralId)
    .then((res) => {
      this._log("Disconnected", res.value);
      this.setState({
        status : "Disconnected",
        isConnected: false,
    })
    });
  };

  listService(){
  }

  subscribeSvc(){
  }

  _log = (text: string, ...args) => {
    const message = "*" + text + args;
    this.setState({
      text: [message, ...this.state.text]
    });
  };

  _logError = (tag: string, error: BleError) => {
    this._log(
      tag +
        "ERROR(" +
        error.errorCode +
        "): " +
        error.message +
        "\nREASON: " +
        error.reason +
        " (att: " +
        error.attErrorCode +
        ", ios: " +
        error.iosErrorCode +
        ", and: " +
        error.androidErrorCode +
        ")"
    );
  };

  render() {
    const {deviceOn,isConnected} = this.state;
    return (
      <View style={styles.container}>
        <View style={[styles.boxContainer, styles.boxOne]}>
            <Text margin="10" style={{color: '#4d4d4d', fontFamily: 'Kailasa-Bold', fontSize: 45, fontWeight: 'bold'}}>
                {this.state.status}
            </Text>
        </View>
        <View style={[styles.boxContainer, styles.boxTwo]}>
            <Text margin="8" style={{fontSize: 20}}>Status log:</Text>
            <FlatList
              style={styles.container}
              data={this.state.text}
              renderItem={({ item }) => <Text> {item} </Text>}
              keyExtractor={(item, index) => index.toString()}
              />
        </View>

        {deviceOn ? (
        <View style={[styles.boxContainer, styles.boxThree]}>
          {!isConnected  && deviceOn ? (    
            <Button
              textStyle={{fontSize: 18, fontWeight: '500'}}
              large={true}
              loading={false}
              size={'small'}
              rounded={true}
              loadingProps={{size:'small', color:'#000000'}}
              activityIndicatorStyle={{flex:1}}
              buttonStyle={{backgroundColor:'#09556B'}}
              title="Connect"
              onPress={() => this.connectBle(this.state.scanneddevice) } 
              /> ) : (<Button
                textStyle={{fontSize: 18, fontWeight: '500'}}
                large={true}
                loading={false}
                rounded={true}
                size={'small'}
                loadingProps={{size:'small', color:'#000000'}}
                activityIndicatorStyle={{flex:1}}
                buttonStyle={{backgroundColor:'#09556B'}}
                title="Disconnect"
                onPress={() => this.disconnect() } />)}
        </View>) : (
          <View style={[styles.boxContainer, styles.boxThree]}>
            <Button
              textStyle={{fontSize: 18, fontWeight: '500'}}
              large={true}
              loading={false}
              rounded={true}
              size={'small'}
              loadingProps={{size:'small', color:'#000000'}}
              activityIndicatorStyle={{flex:1}}
              title="Scan"
              buttonStyle={{backgroundColor:'#09556B'}}
              onPress={() => this.scanBle()}/>
          </View>
          )}
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
  },
  boxContainer: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  boxOne: {
    flex: 3,
    fontSize: 30,
    textAlign: 'left',
    backgroundColor: '#B9DDE7',
  },
  boxTwo: {
    flex: 2,
    fontSize: 15,
    textAlign: 'left',
    alignItems: 'flex-start',
    backgroundColor: '#8FC6D6',
  },
  boxThree: {
    flex: 1,
    fontSize: 15,
    justifyContent: 'space-around',
    flexDirection: 'row',
    backgroundColor: '#008BB2',
  },
});
