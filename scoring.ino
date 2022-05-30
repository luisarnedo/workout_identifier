#include "thingProperties.h"
#include "WorkoutClassifier.h"
#include <Arduino_LSM6DS3.h>
#include "BinaryClassifier.h"

float x, y, z;
float xg,yg,zg;
float counter_1,counter_2,counter_3,counter_4;

Window window;
Eloquent::ML::Port::WorkoutClassifier clf_multi;
Eloquent::ML::Port::BinaryClassifier clf_bin;

void setup() {
  Serial.begin(9600);
  delay(1500);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1) delay(1000);
  }

  delay(1500);
}

void loop() {
  ArduinoCloud.update();


  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
    IMU.readAcceleration(x, y, z);
    IMU.readGyroscope(xg, yg, zg);

    float sample[] = {x*100, y*100, z*100, xg, yg, zg};

    if (!window.transform(sample))
        return;

    Serial.print("State: ");
    state=clf_bin.predictLabel(window.features);
    Serial.println(state);
    
    if(state=="Activity"){
      Serial.print("Exercicise: ");
      exercise = clf_multi.predictLabel(window.features)
      Serial.println(exercise);

      switch (exercise) {
        case "Push up":
          counter_1= counter_1+1;
          case "Push up":
            counter_1 = counter_1+1;
            break;
          case "Squat":
            counter_2 = counter_2+1;
            break;
          case "Lunge":
            counter_3 = counter_3+1;
            break;
          case "Push up":
            counter_4 = counter_4+1;
            break;
      }

    }
  }

  delay(50);
}
