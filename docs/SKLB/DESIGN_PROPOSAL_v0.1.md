# SKLB (Saklob) Command Operating Environment

## Arkitektura at Disenyo v0.1 

### 1. Panimula

Ang **SKLB (Saklob)** ay isang *CLI-based Command Operating Environment* na idinisenyo bilang pangunahing kapaligiran ng pamamahala, pagpapatakbo, pagmamanman, at pagsasaayos ng mga sistemang kabilang sa ekosistemang **LNDH (LundayHangin)**.

Bagama't humango ng inspirasyon mula sa **Linux Shell** at **Cisco IOS CLI**, hindi layunin ng SKLB na maging salin o replika ng alinman sa mga ito. Sa halip, layunin nitong bumuo ng isang sariling wikang pang-command, sariling gramatika, at sariling pilosopiya na higit na angkop sa mga distributed embedded systems, robotics, at cyber-physical systems.

---

# 2. Pilosopiya

Nakabatay ang SKLB sa mga sumusunod na prinsipyo:

* **Domain-oriented**, hindi lamang user-oriented.
* **Distributed-first**, sapagkat ang LNDH ay binubuo ng maraming MCU o nodes.
* **Context-aware**, kung saan malinaw ang pagkakaiba ng execution at configuration.
* **Consistent grammar**, upang pare-pareho ang interpretasyon ng bawat bahagi ng prompt at bawat command.
* **Filipino-native terminology**, bilang pagkakakilanlan ng sistema.

---

# 3. Arkitektura ng Ekosistema

```
LNDH Ecosystem
│
├── dron      (Airship Node)
├── tangan    (Remote Controller)
├── daong     (Docking Base)
└── himpil    (Ground Control Station)
```

Bawat node ay maaaring magkaroon ng sariling SKLB session.

---

# 4. User Domains

May tatlong pangunahing user domains.

```
Balana
Malim
Bahala
```

### Balana

Karaniwang operasyon.

Mga halimbawa:

* pagmamanman
* pagtingin ng impormasyon
* simpleng pagpapatakbo

---

### Malim

Operator domain.

Mga halimbawa:

* diagnostics
* maintenance operations
* calibration
* pagsusuri

---

### Bahala

Administrator domain.

Mga halimbawa:

* configuration
* user management
* service control
* firmware management

---

# 5. Salig

Ang **Salig** ang katumbas ng **Root Context**.

Hindi ito ordinaryong user domain.

Ito ang pinakamataas na antas ng command operating environment.

Mga tungkulin:

* system recovery
* low-level maintenance
* SKLB management
* boot environment
* emergency administration

---

# 6. Domain at Context

Ang bawat domain ay maaaring magkaroon ng isa o higit pang contexts.

Halimbawa

```
Bahala
    ├── kumpig
    ├── kom
    ├── lambat
```

```
Malim
    ├── suri
    ├── kalibrasyon
```

```
Balana
    ├── masid
```

Samantala, ang Salig ay maaaring magkaroon ng sarili nitong domain contexts.

```
Salig
    └── saklob
            └── kumpig
```

---

# 7. Prompt Grammar

Opisyal na gramatika ng prompt:

```
[identity@]system(node)[:domain[(context)]]prompt
```

kung saan:

```
identity   -> session identity (opsyonal)
system     -> ecosystem
node       -> target node
domain     -> user o system domain
context    -> subcontext ng domain
prompt     -> execution o configuration state
```

---

# 8. Mga Halimbawa

## Walang user accounts

```
lndh(dron):balana>

lndh(dron):malim>

lndh(dron):bahala>

lndh(dron):bahala(kumpig)#

lndh(dron):bahala(kom)#

lndh(dron):balana(masid)>
```

---

## May user accounts

```
haraya@lndh(dron):balana>

haraya@lndh(dron):malim>

haraya@lndh(dron):bahala>

haraya@lndh(dron):bahala(kumpig)#
```

---

## Root Context

```
salig@lndh(dron)>

salig@lndh(dron):saklob(kumpig)#
```

---

# 9. Kahulugan ng Prompt Symbols

```
>
```

Execution Prompt.

Nasa execution context.

Walang aktibong configuration editor.

---

```
#
```

Configuration Prompt.

May aktibong configuration context.

Maaaring magsagawa ng mga pagbabagong permanente sa configuration.

Hindi ito nangangahulugang administrator lamang; ito ay nagpapahiwatig na ang kasalukuyang domain ay nasa configuration state.

---

# 10. Daloy ng Pag-access

```
Salig
│
└── Balana
      ├── Malim
      └── Bahala
```

Ang Balana ang karaniwang entry point.

Mula rito ay maaaring pumasok sa:

* Malim
* Bahala

ayon sa wastong pagpapatunay (authentication).

---

# 11. Hybrid Identity Model

Sinusuportahan ng SKLB ang dalawang uri ng deployment.

## Appliance Mode

Walang user accounts.

```
lndh(dron):balana>
```

---

## Multi-user Mode

May identities.

```
haraya@lndh(dron):balana>
```

Pareho ang syntax ng buong CLI.

Nagdaragdag lamang ng identity ang multi-user deployment.

---

# 12. Disenyong Semantiko

Bawat delimiter ay may iisang kahulugan.

```
@
```

Identity separator.

---

```
()
```

Qualifier.

Ginagamit sa node at context.

---

```
:
```

Domain separator.

---

```
>
```

Execution state.

---

```
#
```

Configuration state.

---

# 13. Pangmatagalang Layunin

Bagama't ang unang implementasyon ay para sa ekosistemang LNDH, ang SKLB ay idinisenyo bilang isang pangkalahatang Command Operating Environment na maaaring gamitin sa iba pang distributed embedded systems, robotics platforms, industrial controllers, at autonomous cyber-physical systems.

Sa paglipas ng panahon, maaaring magkaroon ang SKLB ng mga karagdagang domain, contexts, authentication mechanisms, remote sessions, scripting facilities, at automation framework nang hindi binabago ang pundamental na gramatika ng prompt at command environment.

---

# 14. Disenyong Prinsipyo

**Isang prompt. Isang kahulugan. Isang gramatika.**

Ang bawat bahagi ng prompt ay may iisang semantikong tungkulin. Ang bawat delimiter ay may tiyak na gamit. Ang bawat domain ay kumakatawan sa isang malinaw na konteksto ng operasyon. Sa pamamagitan nito, ang SKLB ay nagiging hindi lamang isang command-line interface, kundi isang maayos na dinisenyong command operating environment na may sariling pagkakakilanlan at sariling wikang teknikal.
