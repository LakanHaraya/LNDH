#


# Balangkas na "*LNDH Korpus Teknikal*"

``` txt
docs/
├── 00_overview/
│   ├── README.md
│   ├── vision.md
│   ├── scope.md
│   ├── assumptions.md
│   ├── constraints.md
│   ├── glossary.md
│   ├── audience.md
│   └── maturity_level.md
│
├── 01_governance/
│   ├── design_principles.md
│   ├── coding_standards.md
│   ├── documentation_rules.md
│   ├── decision_process.md 
│   └── change_policy.md
│
├── 02_architecture/
│   ├── responsibility_scope.md
│   ├── ecosystem_architecture.md
│   ├── system_architecture.md
│   ├── subsystem_architecture.md
│   ├── node_roles.md
│   ├── trust_boundaries.md
│   └── data_flow/
│       ├── telemetry_flow.md
│       ├── command_flow.md
│       └── update_flow.md
│
├── 03_requirements/
│   ├── functional/
│   │   ├── system_requirements.md
│   │   ├── node_requirements.md
│   │   └── interface_requirements.md
│   │
│   ├── nonfunctional/
│   │   ├── performance.md
│   │   ├── reliability.md
│   │   ├── scalability.md
│   │   └── maintainability.md
│   │
│   └── safety/
│       ├── hazard_analysis.md
│       ├── fail_safe_policy.md
│       └── operating_limits.md
│
├── 04_design/
│   ├── hardware/
│   │   ├── block_diagrams/
│   │   ├── schematics/
│   │   ├── power/
│   │   │   ├── power_budget.md
│   │   │   └── brownout_strategy.md
│   │   └── bom/
│   │
│   ├── firmware/
│   │   ├── resource_limits.md
│   │   ├── architecture.md
│   │   ├── module_map.md
│   │   ├── state_machine/
│   │   │   ├── global_states.md
│   │   │   ├── per_node_states.md
│   │   │   └── fault_states.md
│   │   ├── timing/
│   │   │   ├── time_model.md
│   │   │   └── sync_quality.md
│   │   └── boot_and_recovery.md
│   │
│   └── software/
│       ├── architecture.md
│       ├── service_layers.md
│       ├── api/
│       │   ├── internal_api.md
│       │   └── external_api.md
│       ├── config/
│       │   ├── schema.md
│       │   └── defaults.md
│       └── persistence/
│           ├── data_model.md
│           └── retention_policy.md
│
├── 05_interfaces/
│   ├── message_lifecycle.md
│   ├── communication/
│   │   ├── transport.md
│   │   ├── addressing.md
│   │   └── qos_policy.md
│   ├── message_formats/
│   │   ├── telemetry.md
│   │   ├── command.md
│   │   └── events.md
│   ├── error_model/
│   │   ├── error_codes.md
│   │   └── recovery_actions.md
│   └── version_negotiation.md
│
├── 06_nodes/
│   ├── PS_airship/
│   │   ├── role_definition.md
│   │   ├── hardware_profile.md
│   │   ├── firmware_profile.md
│   │   └── failure_modes.md
│   ├── MK_controller/
│   │   └── ...
│   ├── TD_docking/
│   │   └── ...
│   └── KL_ground_station/
│       └── ...
│
├── 07_operations/
│   ├── deployment.md
│   ├── provisioning.md
│   ├── startup_shutdown.md
│   ├── monitoring.md
│   ├── logging.md
│   ├── safe_state_recovery.md
│   └── field_maintenance.md
│
├── 08_testing/
│   ├── test_strategy.md
│   ├── test_levels/
│   │   ├── unit.md
│   │   ├── integration.md
│   │   ├── system.md
│   │   └── fault_injection.md
│   ├── simulation.md
│   └── acceptance.md
│
├── 09_security/
│   ├── threat_model.md
│   ├── trust_and_identity.md
│   ├── key_management.md
│   ├── secure_update.md
│   └── incident_response.md
│
├── 10_release/
│   ├── versioning.md
│   ├── changelog.md
│   ├── upgrade_paths.md
│   └── deprecation.md
│
└── 11_appendix/
    ├── naming_conventions.md
    ├── design_decisions/
    │   ├── adr_0001.md
    │   └── adr_0002.md
    ├── references.md
    ├── diagrams/
    └── open_questions.md

```

---

## Filipino

``` txt
doku/
├── 00_sulyap/
│   ├── README.md
│   ├── bisyon.md
│   ├── saklaw.md
│   ├── hinala.md
│   ├── limitasyon.md
│   ├── glosaryo.md
│   ├── mambabasa.md
│   └── antas_ng_kahinugan.md
│
├── 01_pamumuno/
│   ├── prinsipyo_ng_disenyo.md
│   ├── pamatayan_pangkodigo.md
│   ├── tuntunin_ng_dokumentasyon.md
│   ├── proseso_ng_pagpapasiya.md 
│   └── patakaran_sa_pagbago.md
│
├── 02_arkitektura/
│   ├── saklaw_ng_responsibilidad.md
│   ├── arkitektura_ng_ekosistema.md
│   ├── arkitektura_ng_sistema.md
│   ├── arkitektura_ng_subsistema.md
│   ├── tungkulin_ng_sugpong.md
│   ├── hanggahan_ng_tiwala.md
│   └── daloy_ng_datos/
│       ├── daloy_ng_telemetriya.md
│       ├── daloy_ng_utos.md
│       └── daloy_ng_pagsasapanahon.md
│
├── 03_kahingian/
│   ├── pumapagana/
│   │   ├── kahingian_ng_sistema.md
│   │   ├── kahingian_ng_sugpong.md
│   │   └── kahingian_ng_sangrabaw.md
│   │
│   ├── dipumapagana/
│   │   ├── pagtatanghal.md
│   │   ├── pagkamaaasahan.md
│   │   ├── pagkamasusukat.md
│   │   └── pagmamantene.md
│   │
│   └── kaligtasan/
│       ├── pagsusuri_ng_panganib.md
│       ├── patakaran_sa_ligtas_na_pagkabigo.md
│       └── limitasyon_sa_pagpapatakbo.md
│
├── 04_disenyo/
│   ├── materyal/
│   │   ├── dayagram_na_bloke/
│   │   ├── eskematiko/
│   │   ├── koryente/
│   │   │   ├── badyet_pangkoryente.md
│   │   │   └── estratehiya_sa_kawalang_koryente.md
│   │   └── talaan_ng_materyales/
│   │
│   ├── tatagsil/
│   │   ├── hanggahan_ng_mapagkukunan.md
│   │   ├── arkitektura.md
│   │   ├── mapa_ng_modyul.md
│   │   ├── makina_ng_estado/
│   │   │   ├── estado_pangmalawakan.md
│   │   │   ├── estado_pansugpungan.md
│   │   │   └── estado_pangkasiraan.md
│   │   ├── pagsasaoras/
│   │   │   ├── modelo_ng_oras.md
│   │   │   └── kalidad_ng_kasabayan.md
│   │   └── pagbanhaw_at_pagbawi.md
│   │
│   └── lohisil/
│       ├── arkitektura.md
│       ├── latag_ng_serbisyo.md
│       ├── api/
│       │   ├── panloob_api.md
│       │   └── panlabas_api.md
│       ├── kumpig/
│       │   ├── eskema.md
│       │   └── paunang_takda.md
│       └── pagtitiyaga/
│           ├── modelo_ng_datos.md
│           └── patakaran_sa_pagpapanatili.md
│
├── 05_sangrabaw/
│   ├── siklo_ng_mensahe.md
│   ├── komunikasyon/
│   │   ├── paghatid.md
│   │   ├── pagtugon.md
│   │   └── patakaran_sa_kns.md
│   ├── kayarian_ng_mensahe/
│   │   ├── telemetriya.md
│   │   ├── utos.md
│   │   └── kaganapan.md
│   ├── modelo_ng_kamalian/
│   │   ├── kodigo_ng_kamalian.md
│   │   └── galaw_sa_pagbawi.md
│   └── negosasyon_ng_bersiyon.md
│
├── 06_sugpong/
│   ├── PS_lundayhangin/
│   │   ├── katuringan_ng_tungkulin.md
│   │   ├── anyo_ng_materyal.md
│   │   ├── anyo_ng_tatagsil.md
│   │   └── moda_ng_kabiguan.md
│   ├── MK_kontroler/
│   │   └── ...
│   ├── TD_daungan/
│   │   └── ...
│   └── KL_himpilan_sa_lupa/
│       └── ...
│
├── 07_operasyon/
│   ├── pagdeploy.md
│   ├── paglalaan.md
│   ├── pagsisimula_at_pagpipinid.md
│   ├── pagmanman.md
│   ├── paglilista_ng_datos.md
│   ├── pagbabalik_sa_ligtas_na_estado.md
│   └── pagmamantene_sa_larangan.md
│
├── 08_pagsubok/
│   ├── estratehiya_sa_pagsubok.md
│   ├── antas_ng_pagsubok/
│   │   ├── yunit.md
│   │   ├── integrasyon.md
│   │   ├── sistema.md
│   │   └── pagturok_ng_kasiraan.md
│   ├── simulasyon.md
│   └── pagtanggap.md
│
├── 09_seguridad/
│   ├── modelo_ng_banta.md
│   ├── tiwala_at_pagkakakilanlan.md
│   ├── pamamahala_ng_susi.md
│   ├── matiwasay_na_pagsasapanahon.md
│   └── tugon_sa_insidente.md
│
├── 10_lathala/
│   ├── pagbebersiyon.md
│   ├── talabaguhan.md
│   ├── landas_ng_pagsasapanahon.md
│   └── pagkaluma.md
│
└── 11_apendiks/
    ├── talaan_ng_pangalan.md
    ├── pasiya_sa_disenyo/
    │   ├── tpa_0001.md
    │   ├── tpa_0002.md
    │   └── ...
    ├── sanggunian.md
    ├── dayagram/  
    └── katanungang_bukas.md

```