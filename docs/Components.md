# Balangkas ng Ekosistema ng LNDH

Ang **LundayHangin (LNDH)** ay isang integrated airship ecosystem na binubuo
ng apat na pangunahing komponent. Bawat isa ay may natatanging tungkulin
ngunit nakikipag-ugnayan sa iba sa pamamagitan ng serial, wireless (WiFi
Bluetooth), o RF links. Layunin nitong maging modular, scalable, at madaling
i-deploy para sa mga hobbyist at R&D applications.

## Mga Komponent:

| Kodigo | Pangalan | Papel |
| :---: | :--- | :--- |
| **PS** | *Pangunahing Sasakyan* | Ang mismong airship — tumatanggap ng utos mula sa **MK** o **KL**, nagpapadala ng telemetriya papunta sa **MK** at **KL**, at may kakayahang bumalik sa **TD** para sa recharge o diagnostics. |
| **MK** | *Malayuang Kontroler* | Ang remote control ng piloto — nag-uutos sa **PS** at **TD** at sabay na nagsusumite status data sa **KL**. Nagpapatakbo ng non-blocking loop para sa tuloy-tuloy na komuikasyon at input handling. |
| **TD** | *Takad Daungan* | Docking base — nagbibigay ng power, recharging, diagnostic interface sa **PS**. Nagpapadala din ng update sa **PS** at **KL** para sa maintenance at health check status. |
| **KL** | *Kontrol sa Lupa* | Ground control station o central monitoring server o hub (maaaring PC o Raspberry Pi). Tumatanggap ng data mula sa **MK**, **TD**, at **PS** at may kakayahang magpadala ng override o mission commands pabalik sa mga ito. |

### Prinsipyo ng Arkitektura

1. **Modular and Independent Control Layers**
    - Lahat ng komponent ay maaaring magpatakbo ng sariling firmware loop at protocol layer.
    - Ginagamit ang pare-parehong eskema ng komunikasyon (JSON packets o custom binary protocol).

2. **Real-time and Non-blocking Operations**
    - Ang bawat `loop()` sa mga mikrokontroler ay gumagamit ng non-blocking timing (`millis()`-based) upang mapanatiling tuloy-tuloy ang komunikasyon.

3. **Redundant Communication Links**
    - Ang **PS** ay may pangunahing link sa **MK**, ngunit may backup telemetry sa **KL** sa pamamagitan ng parehong comm schema.

4. **Scalable Data Network**
    - Maaaring madagdagan ang mga subsystem (hal. *sensor pods* o *relay drones*)