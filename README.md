# saw-trap-buzzer-inspired

PWM-based Arduino experiments to approximate industrial buzzer and trap-like siren sounds (SAW‑inspired).

## Overview
This repository collects Arduino sketches, wiring notes and tuning tips for recreating buzzer / siren effects using PWM on Arduino UNO. The goal is experimentation and documentation.

## Quick start
Required hardware:
- Arduino UNO (or compatible)
- small speaker + amplifier (LM386 for example)
- 2 resistor of 100ohm
- 10uF capacitor
- potentiometer

## Design principles & tips
- Arduino UNO produces square-wave PWM (via `tone()`); fidelity is limited but good for buzzer-like sounds.
- To make the sound “less perfect” and more buzzer-like:
  - rapid frequency patterning (e.g. 1200‑1250‑1300‑1250‑1200)
  - introduce small random frequency jitter
  - simulate 50Hz tremolo to mimic AC-powered mechanical buzzers

## Legal / copyright
- This project is *inspired by* buzzer/siren sounds in films. It does NOT include any copyrighted movie audio.
