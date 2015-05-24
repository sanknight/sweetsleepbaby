import processing.serial.*;
 
// The serial port:
Serial myPort;
String dataReading = "";
String [] dataOutput = {};
float brightness = 100;
Float ax, ay, az;
void setup() {
size(500,500);
 
// Open the port you are using at the rate you want:
myPort = new Serial(this, Serial.list()[0],9600); 
//in my case,the Serial port the Arduino is connected to is 9th on the serial list, hence the [8]
//to get access to the serial list you can use >> println(Serial.list());
myPort.bufferUntil('\n');
 
}
 
void draw() {
 
}
 
void serialEvent(Serial myPort) {
  dataReading = myPort.readString();
  String[] vals = dataReading.split(" ");
  background(0,55,brightness);
  
  az  = Float.parseFloat(vals[2]);
  
  
  int az1 = int(az);
  if (az1  > 360 && az1 < 370)
  {
    
      background(0,180,brightness);
  }
  
   else
   {
     background(0,45,brightness);
   }
  
 
 //if( dataReading != "-1416  -15452  -5648  -387  -80  44")
//if(ax > 150 && ax < 300 )
 //{
   //if( ay > 400 && ay < 700)
   //{
    // if( az > 15800 && az < 16100)
     //{
      //   background(0,0,brightness);
     //}
   //}
 //}
  
 if(dataReading!=null){
    dataOutput = append(dataOutput, dataReading);
    saveData(); 
  } 
}
 
 
void saveData() {
  println("saving to txt file...");
  saveStrings("D:/data/data.txt", dataOutput); 

}