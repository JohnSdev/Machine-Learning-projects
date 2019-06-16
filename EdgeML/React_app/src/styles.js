import { Dimensions, StyleSheet, Platform, } from 'react-native';

export const SCREEN_WIDTH  = Dimensions.get('window').width;
export const SCREEN_HEIGHT = Dimensions.get('window').height;
export const NAVBAR_HEIGH  = Platform.OS === 'ios' ? 64 : 54;
export const TABBAR_HEIGH  = Platform.OS === 'ios' ? 49 : 49;

//http://paletton.com/#uid=13t0u0kiCFn8GVde7NVmtwSqXtg
export const hiotColors = {
  ok: [
    'rgb(115,186,89)'//'#43A047'
  ],
  warning: [
    'rgb(248,175,51)'//'#FBC02D'
  ],
  alert: [
    '#d9534f'
  ],
  value: [
    '#2980b9'
  ],
  button: [
    //'rgb(55, 126, 164)',
    'rgba(0,54,76,0.8)',
  ],
  //Used 1 is active and 0 none active.
  // notification: [
  //   '#E53935',
  //   '#FBC02D',
  //   '#43A047',
  //   'rgb(0,54,76)',
  //   'rgb(245,236,201)',
  // ],
  loginBackGround: [
    'rgb(0,54,76)',
    'rgb(32, 57, 74)',
  ],
  tabBar: [
    'rgb(55, 126, 164)',
    // 'rgb(177, 217, 238)',
    // 'rgb(55, 126, 164)',
  ],
  topNavBar:
    'rgb(55, 126, 164)'
  ,
  navBar:
    //'rgba(0,54,76, 0.8)',
    'rgb(227,227,227)',
    // 'rgb(0,54,76)',

  black:
    'rgb(0, 0, 0)'
  ,
  white:
    'rgb(255, 255, 255)'
  ,
  blue: [
    'rgb(10, 70, 130)',
    'rgb(0,159,228)',
    'rgb(125, 200, 240)',
    'rgb(200,230,250)',
    'rgb(226,242,252)',
  ],
  pink: [
    'rgb(140, 0, 90)',
    'rgb(230,0,126)',
    'rgb(240,165,195)',
    'rgb(250, 210, 230)',
    'rgb(252,232,242)',
  ],
  green: [
    'rgb(115, 186, 89)',
    'rgb(176, 203, 11)',
    'rgb(210,225,130)',
    'rgb(235, 240, 190)',
    'rgb(245,247,222)',
  ],
  brown: [
    'rgb(153,73,22)',
    'rgb(255, 185, 0)',
    'rgb(255,229,126)',
    'rgb(254, 245, 178)',
    'rgb(254,250,216)',
  ],
  grey: [
    'rgb(54,54,54)',
    'rgb(142,139,137)',
    '#bbb',
    'rgb(238,238,238)',
    'rgb(348,348,348)',
  ],
  beige: [
    'rgb(230,229,223)',
    'rgb(242,238,230)',
    'rgb(248,246,240)',
  ],
  cream:
    'rgb(245,236,201)'
  ,
  orange:
    'rgb(248,175,51)'
  ,
  blueish:
    'rgb(55, 126, 164)',
}

export default {
  // layout/container related
  container: {
    flex:1,
    backgroundColor: hiotColors.white,
  },
  horizontal: {
    flex: 1,
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
  },
  vertical: {
    flexDirection: 'column',
  },
  marginToNavbar: {
    marginTop: NAVBAR_HEIGH,
  },
  transparent: {
    backgroundColor: 'rgba(0, 0, 0, 0)',
  },
  semiTransparent: {
    backgroundColor: 'rgba(10,10,10,0.5)',
  },
  // Text styles
  link: {
    textAlign: 'center',
    color: hiotColors.blue[1],
  },
  buttonText: {
    fontSize: 14,
    color: 'white',
  },
  // Navbar Stuff
  name: {
    color: 'black',
    margin: 10,
    fontSize: 14,
  },
  row: {
    flexDirection: 'row',
  },
  col: {
    flex: 1,
    flexDirection: 'column',
    alignItems: 'center',
  },
  navBarContainer: {
    top: 0,
    //position: 'absolute',
    //flex:1,
    //flexDirection: 'row',
    // borderBottomColor: hiotColors.grey[2],
    // borderBottomWidth: StyleSheet.hairlineWidth,
    // width: SCREEN_WIDTH,
    height: NAVBAR_HEIGH,
  },
  hiotBorders: {
    backgroundColor: hiotColors.white,
    borderWidth: 0.5,
    borderColor: '#e1e8ee',
    shadowColor: 'rgba(0,0,0,.2)',
    shadowRadius: 0,
    shadowOffset: {height:0, width: 0}
  },
  greyToolbar: {
    backgroundColor: hiotColors.grey[2], // 'rgba(192,192,192,0.2)',
    flex:1,
    paddingTop: Platform.OS === 'ios' ? 6 : 2, //64 total height of navbar on ios. Title and navigation 44.
    flexDirection: 'row'
  },
  greyToolbarTitle:{
    color: hiotColors.button[0],
    fontSize: 16,
    paddingTop: 2,
    alignSelf: 'center',
    textAlign: 'center',
    fontFamily: 'Poppins-Medium',
    flex:1
  },
  greyNavBarIcon: {
    fontSize: 24,
    alignSelf: 'center',
    color: hiotColors.button[0],
  },
  toolbar: {
    backgroundColor: hiotColors.blueish, // 'rgba(192,192,192,0.2)',
    flex:1,
    paddingTop: Platform.OS === 'ios' ? 6 : 2, //64 total height of navbar on ios. Title and navigation 44.
    flexDirection: 'row'
  },
  toolbarTitle:{
    color: hiotColors.white,
    fontSize: 16,
    paddingTop: 2,
    alignSelf: 'center',
    textAlign: 'center',
    fontFamily:'Poppins-Medium',
    flex:1
  },
  navBarLeftButton: {
    width: 50,
    alignItems: 'center',
    justifyContent:'center',
    opacity: 1,
  },
  navBarRightButton: {
    width: 50,
    alignItems:'center',
    justifyContent:'center',
    opacity: 1,
  },
  navBarIcon: {
    fontSize: 22,
    alignSelf: 'center',
    color: hiotColors.white,
  },
  largeButton: {
    height:48,
    margin:10,
    justifyContent:'center',
    flexDirection:'row',
    backgroundColor: hiotColors.button
  },
  smallButton: {
    backgroundColor: 'rgba(255, 255, 255, 0.8)',
    marginTop: 16,
    height: 24,
    width: 60,
    borderRadius: 10,
  },
  smallTextButton: {
    color: hiotColors.grey[0],
    fontFamily:'Poppins-Medium',
    alignSelf: 'center',
    fontSize: 12,
  },
  smallActiveButton: {
    backgroundColor: 'rgba(200, 200, 200, 0.9)',
    marginTop: 8,
    height: 28,
    width: 70,
    borderRadius: 20,
  },
  headline: {
    fontSize: 18,
    fontFamily:'Poppins-Medium',
    //fontWeight: 'bold',
    color: hiotColors.grey[1],
    marginTop: 10
  },
  content: {
    //flex:1,
    fontSize: 14,
    fontFamily:'NotoSerif',
    //fontWeight: 'bold',
    color: hiotColors.grey[0],
    marginTop: 10
  },
  section: {
    padding: 16,
    paddingTop: 0,
  },
  label: {
    fontFamily: 'Poppins-Medium',
    color: hiotColors.grey[1],
  },
};

export const iosDevices = {
  iPhone4s: {
    width: 320,
    height: 480,
  },
  iPhone5: {
    width: 320,
    height: 568,
  },
  iPhone5s: {
    width: 320,
    height: 568,
  },
  iPhone6: {
    width: 375,
    height: 667,
  },
  iPhone6s: {
    width: 375,
    height: 667,
  },
  iPhone7: {
    width: 375,
    height: 667,
  },
  iPhone6Plus: {
    width: 414,
    height: 736,
  },
  iPhone6sPlus: {
    width: 414,
    height: 736,
  },
  iPhone7Plus: {
    width: 375,
    height: 667,
  },
};
