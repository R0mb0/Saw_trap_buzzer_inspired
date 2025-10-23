# Saw trap buzzer inspired

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/459f5de40872485a91fc21aecd789a19)](https://app.codacy.com/gh/R0mb0/Saw_trap_buzzer_inspired/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/R0mb0/Saw_trap_buzzer_inspired)
[![Open Source Love svg3](https://badges.frapsoft.com/os/v3/open-source.svg?v=103)](https://github.com/R0mb0/Saw_trap_buzzer_inspired)
[![MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/license/mit)
[![Donate](https://img.shields.io/badge/PayPal-Donate%20to%20Author-blue.svg)](http://paypal.me/R0mb0)

PWM-based Arduino experiments to approximate industrial buzzer and trap-like siren sounds (SAW‑inspired).

## 🔍 Overview
This repository collects Arduino sketches, wiring notes and tuning tips for recreating buzzer / siren effects using PWM on Arduino UNO. The goal is experimentation and documentation.

## ⚡ Quick start
Required hardware:
- Arduino UNO (or compatible)
- small speaker + amplifier (LM386 for example)
- 2 resistor of 100ohm
- 10uF capacitor
- potentiometer

### 🖼️ Electric scheme

![Electric scheme](https://github.com/R0mb0/Saw_trap_buzzer_inspired/blob/main/Fritzing/Sketch.png?raw=true)

## 🧩 Design principles & tips
- Arduino UNO produces square-wave PWM (via `tone()`); fidelity is limited but good for buzzer-like sounds.
- To make the sound “less perfect” and more buzzer-like:
  - rapid frequency patterning (e.g. 1200‑1250‑1300‑1250‑1200)
  - introduce small random frequency jitter
  - simulate 50Hz tremolo to mimic AC-powered mechanical buzzers

## ⚖️ Legal / copyright
- This project is *inspired by* buzzer/siren sounds in films. It does NOT include any copyrighted movie audio.
