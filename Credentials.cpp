
/*** One-time FlashConfig writes may be inserted below... ***/
// NOTE: If you already ran Firmware Version 9.0x, 
// network SSID and password will not be updated just by replacing both 
//       #define NETWORK_NAME and #define NETWORK_PASSWORD at the beginning of the source code, 
// instead, to set network SSID
//       and password in the code instead of setting them up with the clock, 
// uncomment the four lines below and replace
//       MyNetworkName and MyNetworkPassword with the proper strings while keeping the 
// surrounding "double-quotes".

//sprintf(FlashConfig.SSID, ".;.;.;.;.;.;.;.;.;.;.;.;.;.;.;.;.;.;.;.");
//sprintf(FlashConfig.Password, ".:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.");
//sprintf(&FlashConfig.SSID[4], "FritzBoxWLAN");
//sprintf(&FlashConfig.Password[4], "volubly-spruce-moribund-furring");

//#ifdef DEVELOPER_VERSION
//  #include "Credentials.cpp"
//#endif
/***/
