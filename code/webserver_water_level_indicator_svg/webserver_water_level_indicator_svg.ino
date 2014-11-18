
#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
int in1=32;
int in2=28;
int in3 =24;
int in4 =22;

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,2,177);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
     pinMode(in1, INPUT);   
     pinMode(in2, INPUT);     
     pinMode(in3, INPUT);
     pinMode(in4, INPUT);
  


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
	  client.println("Refresh: 1");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html><head><meta charset=\"UTF-8\"><title>IoT with arduino + Ethernet Shield</title></head><body>");
          client.println("<div id=\"waterCup\"><svg id=\"svgg\" version=\"1.1\" baseProfile=\"full\" width=\"250\" height=\"320\" xmlns=\"http://www.w3.org/2000/svg\">");
          client.println("<path d=\"M5 0 L35 314 L205 314 L235 0\" fill=\"none\" stroke-width=\"8\" style=\"stroke:#C2C2D6\" />");
if(digitalRead(in4) == LOW) {
  Serial.println("in4");
        client.println("<path d=\"M34 250 L206 250 L200 309 L40 309 L34 250\" style=\"fill:#40B3F1\" />");
        client.println("<path d=\"M28 191 L212 191 L206 250 L34 250 L28 191\" style=\"fill:#40B3F1\" />");
        client.println("<path d=\"M21 120 L219 120 L212 191 L28 191 L21 120\" style=\"fill:#40B3F1\" />");
        client.println("<path d=\"M15 50 L226 50 L219 120 L21 120 L15 50\" style=\"fill:#40B3F1\" />");

     } 
     else if(digitalRead(in3) == LOW) {
        client.println("<path d=\"M34 250 L206 250 L200 309 L40 309 L34 250\" style=\"fill:#40B3F1\" />");
        client.println("<path d=\"M28 191 L212 191 L206 250 L34 250 L28 191\" style=\"fill:#40B3F1\" />");
        client.println("<path d=\"M21 120 L219 120 L212 191 L28 191 L21 120\" style=\"fill:#40B3F1\" />");
     }    
    else if(digitalRead(in2) == LOW) 
      {
        client.println("<path d=\"M34 250 L206 250 L200 309 L40 309 L34 250\" style=\"fill:#40B3F1\" />");
        client.println("<path d=\"M28 191 L212 191 L206 250 L34 250 L28 191\" style=\"fill:#40B3F1\" />");
     } 
     else if(digitalRead(in1) == LOW) {
        client.println("<path d=\"M34 250 L206 250 L200 309 L40 309 L34 250\" style=\"fill:#40B3F1\" />");

     }   
    else
   {
   //client.println("vide");
   }                 
          client.println("</body></html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
