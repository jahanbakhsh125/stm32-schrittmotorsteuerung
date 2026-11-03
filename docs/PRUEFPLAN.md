# Prüfplan

| Test | Zu prüfendes Verhalten | Ergebnis |
|---|---|---|
| Standardaufruf `9600, 50, CW` | Pulszahl, Frequenz und Ende der Ausgabe messen | Offen |
| Pulszahl 0 | Keine neue Bewegung starten | Offen |
| Pulszahl 1 | Genau ein gewünschter Schrittimpuls | Offen |
| Pulszahlen 65535, 65536 und 65537 | Übergang zwischen den gekoppelten Zählern prüfen | Offen |
| Große Pulszahl | Laufzeit und korrektes Bewegungsende prüfen | Offen |
| Mehrere Geschwindigkeitswerte | Frequenz und Prescaler-Überlauf prüfen | Offen |
| Richtungswechsel | PB5-Pegel und erforderliche Treiber-Vorlaufzeiten messen | Offen |
| Erneuter Start während Bewegung | Definiertes Verhalten ergänzen und prüfen | Offen |
| Mehrere aufeinanderfolgende Bewegungen | Timer-/Interrupt-Zustand und LED prüfen | Offen |

Die Geschwindigkeitsberechnung verwendet `337500 / (1 + RPM)` und übergibt
das Ergebnis als 16-Bit-Prescalerwert. Kleine und große Vorgaben sind auf
Überlauf, nutzbaren Frequenzbereich und den Zusammenhang zur Motordrehzahl zu prüfen.

Ein fehlender HSE-Takt besitzt im vorhandenen Initialisierungspfad keine
ausgearbeitete Fehlerbehandlung. Der Aufruf des Drehgeber-Moduls würde TIM4
umkonfigurieren und ist mit der Timerkette abzustimmen.

Es wurden keine Hardwaremessungen an dieser vorbereiteten Kopie durchgeführt.
