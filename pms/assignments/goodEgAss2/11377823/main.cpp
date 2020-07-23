#include <iostream>
#include <vector>
#include "radar.h"
#include "laser.h"
#include "sonar.h"
#include "rangerfusion.h"

using namespace std;

int main()
{
    Laser myLaser; // creates the Laser, default values
    Radar myRadar; // creates the Radar, default values
    Sonar mySonar; // creates the Sonar, default values

    //Query fixed parameters
    cout << "LASER" << endl;
    cout << "Name: " << myLaser.getSensorName() << endl;
    cout << "Field of View: " << myLaser.getFieldOfView() << endl;
    cout << "Range: " << myLaser.getMinDistance() << " - " << myLaser.getMaxDistance() << "m" << endl << endl;

    cout << "RADAR" << endl;
    cout << "Name: " << myRadar.getSensorName() << endl;
    cout << "Field of View: " << myRadar.getFieldOfView() << endl;
    cout << "Range: " << myRadar.getMinDistance() << " - " << myRadar.getMaxDistance() << "m" << endl << endl;

    cout << "SONAR" << endl;
    cout << "Name: " << mySonar.getSensorName() << endl;
    cout << "Field of View: " << mySonar.getFieldOfView() << endl;
    cout << "Range: " << mySonar.getMinDistance() << " - " << mySonar.getMaxDistance() << "m" << endl << endl;

    //Sets sensor parameters as specified by the user

    //Laser
    cout << "LASER PARAMETERS" << endl;
    cout << "Set Angular Resolution of Laser 15 or 30: " << endl;
    int angularResolution;
    while (1)
    {
        cin >> angularResolution;
        if (myLaser.setAngularResolution(angularResolution))
            break;
        else
        {
            cout << "Invalid. Using last valid value " << myLaser.getAngularResolution() << endl;
            break;
        }
    }

    string laserPort;
    cout << "Set port number" << endl;
    while (1)
    {
        cin >> laserPort;
        if (myLaser.setPort(laserPort))
            break;
        else
        {
            cout << "Invalid. Using last valid value " << myLaser.getPort() << endl;
            break;
        }
    }

    int laserBaud;
    cout << "Set baud rate 38400 or 115200" <<endl;
    while (1)
    {
        cin >> laserBaud;
        if (myLaser.setBaud(laserBaud))
            break;
        else
        {
            cout << "Invalid. Using last valid value " << myLaser.getBaud()<< endl;
            break;
        }
    }

    //Radar
    cout << "RADAR PARAMETERS" << endl;
    cout << "Set Field of View 20 or 40 " << endl;
    int fieldOfView;
    while (1)
    {
        cin >> fieldOfView;
        if (myRadar.setFieldOfView(fieldOfView))
            break;
        else
        {
            cout << "Invalid. Using last valid value " << myRadar.getFieldOfView() << endl;
            break;
        }

    }

    string radarPort;
    cout << "Set port number" << endl;
    while (1)
    {
        cin >> radarPort;
        if (myRadar.setPort(radarPort))
            break;
        else
        {
            cout << "Invalid. Using last valid value " << myRadar.getPort()<<endl;
            break;
        }
    }

    int radarBaud;
    cout << "Set baud rate 38400 or 115200" <<endl;
    while (1)
    {
        cin >> radarBaud;
        if (myRadar.setBaud(radarBaud))
            break;
        else
        {
            cout << "Invalid. Using last valid value " << myRadar.getBaud()<<endl;
            break;
        }
    }


   //Sonar
    cout << "SONAR PARAMTERS" << endl;

    string sonarPort;
    cout << "Set port number" << endl;
    while (1)
    {
        cin >> sonarPort;
        if (mySonar.setPort(sonarPort))
            break;
        else
        {
            cout << "Invalid. Using last valid value " << mySonar.getPort()<<endl;
            break;
        }
    }

    int sonarBaud;
    cout << "Set baud rate 38400 or 115200" <<endl;
    while (1)
    {
        cin >> sonarBaud;
        if (mySonar.setBaud(sonarBaud))
            break;
        else
        {
            cout << "Invalid. Using last valid value " << mySonar.getBaud()<<endl;
            break;
        }
    }

    RangerFusion fusedSensors;

    vector<Ranger*> allTheSensors = {&myLaser,&myRadar, &mySonar};
    fusedSensors.setRangers(allTheSensors);

    /*cout << "RAW DATA" << endl;

    for (int i=0; i<fusedSensors.getRawRangeData().size(); i++)
    {
        for (int j=0;j<fusedSensors.getRawRangeData()[i].size();j++)
        {
            cout << fusedSensors.getRawRangeData()[i][j] << " ";
        }
        cout << endl;
    }*/

    // set fusion method

    int fusionChoice;
    cout << "Enter fusion method 1. min, 2. max, 3. avg" << endl;
    while (1)
    {
        cin >> fusionChoice;
        if (fusedSensors.setFusionMethod(fusionChoice))
        {
            break;
        }
        else
        {
            cout << "Invalid. Using last valid value " << fusedSensors.getFusionMethod()<<endl;
            break;
        }

    }

    while (1)
    {
        myLaser.generateData();
        myRadar.generateData();
        mySonar.generateData();
        fusedSensors.getRawRangeData();
        fusedSensors.getFusedRangeData();

        for(int i=0; i<fusedSensors.getFusedRangeData().size(); i++)
        {
                cout << fusedSensors.getFusedRangeData()[i] << " ";
        }
            cout << endl;
    }
    return 0;

}
