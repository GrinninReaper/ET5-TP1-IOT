
#include <LoRaWan.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "format.pb.h"


unsigned char buffer[128] = {0xef, 0xff, 0x55, 3, 4, 5, 6, 7, 8, 9,};
int id = 666;
int cpt = 0;




void setup(void)
{
    SerialUSB.begin(115200);
    
    lora.init();
    
    lora.initP2PMode(868, SF7, BW125, 8, 8, 20);
}

void loop()
{

	_polytech_Uplink message = {"Kill", 0, "Them all", 0};

	uint8_t buffer[10];

	pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
	pb_encode(&stream, polytech_Uplink_fields, &message);

	char tamponCpt[156];
	sprintf(tamponCpt, "%d", buffer);


    lora.transferPacketP2PMode(tamponCpt);

    SerialUSB.println("Send string.");
    delay(3000);
    lora.transferPacketP2PMode(buffer, 10);
    SerialUSB.println("Send hex.");
    delay(3000);
    cpt++;
}
