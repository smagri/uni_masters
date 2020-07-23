#include "sensor.h"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

#define POLL_SIZE 20

using namespace std;

int main(){
    Sensor sensor1;

    int option = 0;
    int n = 0;
    int end = 0;

    while(end == 0){
        printf("\nSelect option for UTM-XXL:\n");
        printf("1. Display Baud Rate\n");
        printf("2. Change Baud Rate\n");
        printf("3. Display Scan Time\n");
        printf("4. Change Scan Time\n");
        printf("5. Display Angular Resolution \n");
        printf("6. Change Angular Resolution  \n");
        printf("7. Display Port  \n");
        printf("8. Display Range and Field of View  \n");
        printf("9. Start Data Record  \n");
        printf("Press any other key to terminate   \n");

        scanf("%i1 \n",&option);

        while(getchar()!='\n'){
            printf("Session Terminated\n");
            return 0;
        }

        switch (option) {
        case 1:
            printf("Current Baud Rate: %i \n",sensor1.getBaudRate());
            break;
        case 2:
            printf("Change Baud Rate to:\n 1. 38400 \n 2. 115200 \n");
            scanf("%i1",&n);
            sensor1.setBaudRate(n);
            printf("Baud Rate changed to %i \n",sensor1.getBaudRate());
            break;
        case 3:
            printf("Current Scanning Time: %ims/scan \n",sensor1.getScanTime());
            break;
        case 4:
            printf("Change Scanning Time to:\n 1. 50ms/scan \n 2. 25ms/scan \n");
            scanf("%i1",&n);
            sensor1.setScanTime(n);
            printf("Scanning Time changed to %ims/scan \n",sensor1.getScanTime());
            break;
        case 5:
            printf("Current Angular Resolution: %.1f \n",sensor1.getAngRes());
            break;
        case 6:
            printf("Change Angular Resolution to:\n 1. 0.5deg \n 2. 1.0deg \n");
            scanf("%i1",&n);
            sensor1.setAngRes(n);
            printf("Angular Resolution changed to %.1fdeg \n",sensor1.getAngRes());
            break;
        case 7:
            printf("Current Port: /dev/ttyACM%i \n",sensor1.getPort());
            break;
        case 8:
            printf("Field of View: %i degrees \n",sensor1.getFieldOfView());
            printf("Max Distance %im \n",sensor1.getMaxDist());
            printf("Min Distance %.1fm \n",sensor1.getMinDist());
            break;

        case 9:
            for(int i = 1; i<POLL_SIZE; ++i){
                usleep(sensor1.getScanTime()*1000);
                printf("Sequence Number: %i \nDistance = %.1f\n",i,sensor1.getDist());
            }
            break;
        default:
            printf("Session Terminated\n");
            break;
        }
    }
    return 0;
}
