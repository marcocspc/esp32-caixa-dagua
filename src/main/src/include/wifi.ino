void setup_wifi() {
  WiFi.mode(WIFI_AP_STA);
  //tentar primeiro se conectar ao AP
  Serial.print("Tentando conectar-se a ");
  Serial.println(upstream_ssid);
  WiFi.begin(upstream_ssid, upstream_password);
 
  for (int i = 0; i < 5 && WiFi.status() != WL_CONNECTED; i++) {
    delay(500);
    Serial.println("Ainda tentando conectar...");
  }

  if (WiFi.status() != WL_CONNECTED) {
    // Não foi possível se conectar à wi-fi
    WiFi.disconnect();
    Serial.print("Não foi possível se conectar a ");
    Serial.println(upstream_ssid);
    Serial.print("Iniciando AP local com SSID '");
    Serial.print(my_ssid);
    Serial.print("' e senha '");
    Serial.print(my_password);
    Serial.println("'.");
    WiFi.softAP(my_ssid, my_password);

    //Debug:
    Serial.print("Estado da WiFi: ");
    WiFi.printDiag(Serial);

    Serial.print("Meu ip: ");
    Serial.println(WiFi.softAPIP());
  } else {
    // Wi-Fi conectada
    Serial.println("");
    Serial.println("WiFi conectada.");
    Serial.print("Endereço de IP ");
    Serial.println(WiFi.localIP());
  }
}
