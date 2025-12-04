#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const int relay = 25;  // GPIO 25 connected to optocoupler input

// Replace with your network credentials
const char* ssid = "Vodafone-26D6A9";
const char* password = "A4338hEhtV";

AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {font-family: Arial; text-align: center;}
    h2 {font-size: 2.0rem;}
    .switch {position: relative; display: inline-block; width: 60px; height: 34px;}
    .switch input {display: none;}
    .slider {position: absolute; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; transition: .4s;}
    .slider:before {position: absolute; content: ""; height: 26px; width: 26px; left: 4px; bottom: 4px; background-color: white; transition: .4s;}
    input:checked + .slider {background-color: #2196F3;}
    input:checked + .slider:before {transform: translateX(26px);}
  </style>
</head>
<body>
  <h2>Relay Control</h2>
  <label class="switch">
    <input type="checkbox" onchange="toggleRelay(this)" id="relay">
    <span class="slider"></span>
  </label>
<script>
function toggleRelay(element) {
  var xhr = new XMLHttpRequest();
  if(element.checked) { xhr.open("GET", "/relay?state=1", true); }
  else { xhr.open("GET", "/relay?state=0", true); }
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  server.on("/relay", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("state")) {
      String state = request->getParam("state")->value();
      if (state == "1") {
        digitalWrite(relay, HIGH);
        Serial.println("Relay ON");
      } else {
        digitalWrite(relay, LOW);
        Serial.println("Relay OFF");
      }
    }
    request->send(200, "text/plain", "OK");
  });

  server.begin();
}

void loop() {
  // Nothing needed here
}
