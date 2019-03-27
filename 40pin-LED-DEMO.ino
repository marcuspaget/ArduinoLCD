  /* ArduinoLCDHack(c) by Mark Paget

  ArduinoLCDHack is licensed under a Creative Commons Attribution 3.0 Unported License. 
  See <http://creativecommons.org/licenses/by/3.0/>

  */

  // Prep data for following numbers: 8, 80, 0, 1, 2, 3, 5, 8, 13
  int thisMap[9][14]={ {6,5,12,13,19,7,2,3,8,4,11,9,10}, {2,3,8,11,9,10,6,5,18,7,12,13,19}, {6,5,12,13,19,7,2,3,8,11,9,10}, 
                        {6,5,12,13,19,7,8,9}, {6,5,12,13,19,7,2,8,4,11,10}, {6,5,12,13,19,7,2,8,4,9,10}, 
                        {6,5,12,13,19,7,2,3,4,9,10}, {6,5,12,13,19,7,2,3,8,4,11,9,10}, {5,12,2,8,4,9,10} };
  // Labels for display
  String nameMap[9]={
      "08","80", "00", 
      "01", "02", "03",
      "05","08","13"};
  
  void setup() {
    Serial.begin(9600); // Prepare console
    for(int i=2;i<=13;i++) {pinMode(i,OUTPUT);digitalWrite(i,LOW);} // setup all pins [2-13] and turn them off
    for(int i=18;i<=19;i++) {pinMode(i,OUTPUT);digitalWrite(i,LOW);} // setup A4, 5 and turn off
  }
  
  void runLights(int pinMap[],int sizePM, int sizePMZ) {
  
    byte pinCnt=sizePM/sizePMZ; // grab count of pins to turn on for display
    
    Serial.print("Enabling ");
    Serial.print(pinCnt);
    Serial.print("pins: ");
  
    // spin through all pins to turn on
    for(int i=0;i<pinCnt;i++){
      int thisPin=pinMap[i];
      Serial.print(thisPin);Serial.print(" ");
      digitalWrite(thisPin,HIGH);
    }
    
    Serial.print("\n");
  
    // sleep 1.5 seconds whilst showing number
    delay(1500);
    
    Serial.print("Disabling pins: ");
  
    // spin through all pins and turn off
    for(int i=0;i<pinCnt;i++){
      int thisPin=pinMap[i];
      Serial.print(thisPin);Serial.print(" ");
      digitalWrite(thisPin,LOW);
    }
  
    Serial.print("\n");
  }
  
  void loop() {
    // Count number of items to display
    int nameCnt=sizeof(thisMap)/sizeof(thisMap[0]);
  
    // Spin through each item and display in console first then call function to turn on LCD
    for(int i=0;i<nameCnt;i++) {
      Serial.print("\n\nRunning Code ");
      Serial.println(nameMap[i]);
      Serial.println("===========");
      runLights(thisMap[i],sizeof(thisMap[i]),sizeof(thisMap[i][0]));
    }
    Serial.println("\n Running Again .in 5 secs .. \n");
    delay(5000);
  }
