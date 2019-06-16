var noble = require('noble');

const DEVICE_SERVICE_UUID = 'FFE0';
const DEVICE_NAME = 'BLE_IOT_TEMP'; //Change
const SERICE_TEMP = 'FFE1';
export default class BleModule{

	constructor(){
		this.isConnecting = false;
		this.initUUID();
		this.manager = new BleManager();
	}

		
	scanBle(){
		return new Promise( (resolve, reject) =>{
			noble.on('stateChange', function(state) {
				if (state === 'poweredOn') {
					noble.startScanning([DEVICE_SERVICE_UUID]);
					return resolve('done');
				} else {
					noble.stopScanning();
					return reject('No Module Found');
				}
			});
		})
	}
	
	connecBle(){
		noble.on('discover', peripheral => {
			const name = peripheral.advertisement.localName;
			if (name === DEVICE_NAME) { 
					console.log(`Connecting to '${name}' ${peripheral.id}`);
					noble.stopScanning();
					connectAndSetUp(peripheral);
			} else {
					console.log(`Skipping '${name}' ${peripheral.id}`);
			}
		});
	}
	
  connectAndSetUp(peripheral) {
		peripheral.connect(error => {
			const serviceUUIDs = [DEVICE_SERVICE_UUID];
			const characteristicUUIDs = [SERICE_TEMP];
			peripheral.discoverSomeServicesAndCharacteristics(
				serviceUUIDs,
				characteristicUUIDs,
				onServicesAndCharacteristicsDiscovered
			);
		});
	 }

	onServicesAndCharacteristicsDiscovered(error, services, characteristics) {
		const temperatureCharacteristic = characteristics[0];
		temperatureCharacteristic.on('data', (data, isNotification) => {
			console.log('Received: Temp:"' + data + '"');
		});
	}
  subscribeBle(){  			// subscribe to be notified whenever the peripheral update the characteristic
		temperatureCharacteristic.subscribe(error => {
			if (error) {
				console.error('Error subscribing to temperatureCharacteristic');
			} else {
				console.log('Subscribed for temperatureCharacteristic notifications');
			}
		});
	}
}
		/*
			// create an interval to send data to the service
		//   let count = 0;
		//   setInterval(() => {
		//     count++;
		//     const message = new Buffer('hello, ble ' + count, 'utf-8');
		//     console.log("Sending:  '" + message + "'");
		//     temperatureCharacteristic.write(message);
		// 	}, 2500);
// */
