# Anschlüsse und Takt

Die Zuordnung ist aus dem Quellcode abgeleitet. Ein Schaltplan oder ein
nachgewiesener Hardwareaufbau liegt dieser Kopie nicht bei.

| Signal | Anschluss | Hinweis |
|---|---|---|
| Schrittimpuls | PB4 | TIM3_CH1 mit partiellem TIM3-Remapping |
| Richtung | PB5 | High bei `__DIR_CW`, Low bei `__DIR_CCW` |
| Status | PC13 | Low während einer gestarteten Bewegung |

PB4 ist standardmäßig auch ein Debug-Pin. `X_System_Init()` stellt die
SWJ-Konfiguration um; die Einstellung ist mit dem tatsächlichen Debug-Aufbau
abzugleichen. Die Taktfunktion verwendet HSE und PLL mit Faktor 9; der
tatsächliche Quarz und die resultierende Taktfrequenz müssen zum Board passen.

Schritt- und Richtungssignale gehen an einen geeigneten externen Motortreiber.
Ein Motor wird nicht direkt an diese GPIO-Pins angeschlossen. Benötigt werden
die zum Treiber passende Versorgung, gemeinsame Signalmasse und geeignete Pegel.

Der mechanische Drehsinn hängt von Treiber und Motorverdrahtung ab. Die Namen
`CW` und `CCW` beschreiben zunächst nur die im Programm gewählten Signalwerte.
