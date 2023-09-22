#include <ESP8266HTTPUpdateServer.h>

ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

void handleRoot() {
  StreamString temp;
  temp.reserve(500);  // Preallocate a large chunk to avoid memory fragmentation
  temp.printf("<!doctype html><html lang=es><head><meta charset=UTF-8><title>Water heater control</title> <meta name=viewport content='width=device-width,initial-scale=1'> <link rel=icon href=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABgAAAAYCAYAAADgdz34AAAACXBIWXMAAACxAAAAsQHGLUmNAAAAGXRFWHRTb2Z0d2FyZQB3d3cuaW5rc2NhcGUub3Jnm+48GgAAAwhJREFUSIm1VV2ITVEU/s65Z6+975i5MXjw+yCieZCUeBHlReJBGg/Mg58aIS+i8fOCF3kxD0LJX8KDSf4mpQilpAgPGo2SiJRhpvlxz977nL08nOvOvedeOaOsl7PP/vZe3/r2Wntt4D+bl55ovsuFxiImqRCQOplToYbUgNIc3e9Qn+B5/E8E067z9JzjmzLiF0IDZBnSJkTCOsiIm6Txvt44RLuzEgSVP8JhNhnu7t2YO/SnDa37w4dZnZcVTL3OC4OYO5UFCcMtynIkDENYIF/6kk0UCROHyng9FHHPqVMNuzIpoBirycRHetvEg6yR7d46/DjLugAAlHZ+ECHO6hwAyMBlJiDjQKYWbG9n0T8OTV2d3o80JjSLo+sGZqkQgAYkgMJQ3Nf2bOJgrQIDUFTtYN0BPX84Ds82GvS17yp+OHMiv6MSVxYtwvgdgQVEDJB2YA6mdC34UeT8yKb1T2cUAcAvyYUKqwlUxFuVcTsudOZXkebFezaPXDy4Yaj1Ny4NQ2qAdOJcWkBa91xqr7vQ17gnpcAhiKqPVBouUOj3JWPXkzO584Xhny9HA8AbP3THBABpkwCDiPcF1nusjGtL5SApw0oj46ASgVAGVrjwY8ftyUNlPETU/mT8+8o992Z//0Ka11DEVE1gAZXKgdSAikfHIlVjytQWUUPRXc05LA8s7tQckUpVkYoAVepF0vIcMv7lkysGL+x8UDiXKKxtR0s/T+4F0Fs5Vz6iIKWANANhknlp+J0M3eHtjyZ8KCusQ1DPygrI+FWANECuwplKbZR17k09Gy3TqFqC0q5cuko7QSOYeWvut6YyPhYCZYAgdQ/IeoMNxmsujeeRdVuQ81eW8TpJrmejrSJFIA2fJstnryzq7yfjHra+mri3KoCMCoLEWW2r2Pao8PZaKy8T7waa1r5qHkhvVOEYklyvVQDA+i4vBlDjHEjehswEeQ0XxHHub4srTVr2/76qRBDouFtaHL+0ZGAfmeQdJpvkRlpAGAZZBkXJrSbjPC/m12MJ6L/ZL058Y5BoD2/eAAAAAElFTkSuQmCC> <style>html{font-family:Arial;display:inline-block;margin:0 auto;text-align:center}h1{color:#0f3376;padding:2vh}p{font-size:1.5rem}.button{display:inline-block;background-color:#008cba;border:none;border-radius:4px;color:#fff;padding:16px 40px;text-decoration:none;font-size:30px;margin:2px;cursor:pointer}.off{background-color:#f44336}.on{background-color:#008cba}#schedules{display:flex;justify-content:center;align-items:center}ul{font-size:1.5rem;list-style-type:none;list-style-position:outside;padding:0;margin:0 auto;justify-content:center;align-items:center}li{display:table;background-color:#008cba;border:none;border-radius:4px;color:#fff;padding:16px 40px;text-decoration:none;font-size:30px;margin:2px}</style></head><body><h1>Water heater control</h1><p>State: <strong id=state>--</strong></p><p> <button id=button-on class=button>ON</button> <button id=button-off class='button off'>OFF</button></p><h2>Schedules</h2><div id=schedules></div><script>function getState(){const t=new XMLHttpRequest;t.onreadystatechange=function(){if(4==this.readyState&&200==this.status){const t=this.responseText;document.getElementById('state').innerHTML=1==t?'ON':'OFF'}},t.open('GET','http://water-heater.local/get-state',!0),t.send()}function getSchedules(){const t=new XMLHttpRequest;t.onreadystatechange=function(){if(4==this.readyState&&200==this.status){const t=JSON.parse(this.responseText),e=document.createElement('ul');for(const n of t){const t=document.createElement('li'),a=1==n.state?'on':'off';t.classList.add(a),t.textContent=`${n.hour}:${n.minute}`,e.appendChild(t)}document.getElementById('schedules').appendChild(e)}},t.open('GET','http://water-heater.local/get-schedules',!0),t.send()}setInterval(getState,1e4),getState(),getSchedules();const buttonOn=document.getElementById('button-on'),buttonOff=document.getElementById('button-off');function handleClick(t){let e='http://water-heater.local/state-off';'button-on'===t.target.id&&(e='http://water-heater.local/state-on');const n=new XMLHttpRequest;n.onreadystatechange=function(){4==this.readyState&&204==this.status&&getState()},n.open('GET',e,!0),n.send()}buttonOn.addEventListener('click',handleClick),buttonOff.addEventListener('click',handleClick)</script></body></html>");
  server.send(200, "text/html", temp.c_str());
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) { message += " " + server.argName(i) + ": " + server.arg(i) + "\n"; }
  server.send(404, "text/plain", message);
}

void webserver_loop() {
  server.handleClient();
}

void webserver_setup() {
  server.on("/", handleRoot);

  server.on("/get-state", []() {
    uint8_t value = relay_get_state();
    char stringNum[1];
    sprintf(stringNum,"%d",value);
    server.send(200, "text/plain", stringNum);
  });

  server.on("/state-on", []() {
    relay_set_state(HIGH);
    server.send(204);
  });

  server.on("/state-off", []() {
    relay_set_state(LOW);
    server.send(204);
  });

  server.on("/get-schedules", []() {
    String jsonString;
    serializeJson(schedules, jsonString);
    server.send(200, "application/json", jsonString);
  });

  server.on("/set-schedules",HTTPMethod::HTTP_POST, []() {
    String message = setEEPROM_JSON(server.arg("plain"));
    server.send(200, "text/plain", message);
  });

  server.onNotFound(handleNotFound);

  httpUpdater.setup(&server);

  server.begin();
  Serial.println("HTTP server started");
}
