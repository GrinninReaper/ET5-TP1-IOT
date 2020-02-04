
#include <LoRaWan.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "format.pb.h"

//unsigned char buffer[128] = {0, };


void setup(void)
{
    SerialUSB.begin(115200);
    
    lora.init();
    
    lora.initP2PMode(868, SF7, BW125, 8, 8, 20);
}

void loop(void)
{

	_polytech_Uplink message;
	uint8_t buffer[10];

    short length = 0;
    short rssi = 0;
    
    memset(buffer, 0, 128);
    length = lora.receivePacketP2PMode(buffer, 128,  &rssi, 1);

    pb_istream_t stream = pb_istream_from_buffer(buffer, sizeof(buffer));
    pb_decode(&stream, polytech_Uplink_fields, &message);
    
    SerialUSB.print(message.data);

    /*if(length)
    {
        SerialUSB.print("Length is: ");
        SerialUSB.println(length);
        SerialUSB.print("RSSI is: ");
        SerialUSB.println(rssi);
        SerialUSB.print("Data is: ");
        for(unsigned char i = 0; i < length; i ++)
        {
            SerialUSB.print((char) buffer[i]);
        }
        SerialUSB.println();
    }*/
}
