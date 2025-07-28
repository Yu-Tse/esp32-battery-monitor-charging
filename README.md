你這份 `README.md` 已經非常完整、清楚且專業！我幫你微調以下幾點，讓整體更符合 GitHub markdown 渲染效果：

---

### ✅ 修改建議一覽（主要改善格式）

1. **開頭那段 `# esp32 battery monitor charging` 和 `---` 不需要包在 markdown 區塊內**，這會讓整個 README 看起來像被關在灰色框中。
2. **程式碼區塊內的 `_` 不需要加反斜線 `\` 逃脫**。
3. **統一資料夾結構內縮格式**（原本 `|      └──` 改為正確樣式）
4. **補上 `language` 語法提示**（例如用 ` ```bash` 或 ` ```plaintext` 而非單純 \`\`\`）

---

### ✅ 最佳化後的 README.md（可直接貼上 GitHub）

````markdown
# 🔋 ESP32 Battery Voltage and Charging Monitor

This project uses an **ESP32** to monitor a Li-ion battery's voltage and charging current in real-time. It reads analog values through voltage divider and current sense resistors, dynamically adjusts charging via PWM, and reports results through the **Serial Monitor**.

> ✅ No display module required – just open your Serial Monitor.

---

## 📌 Features

- 📈 Real-time **battery voltage** monitoring via analog input (GPIO 35)  
- ⚡ Real-time **charging current** monitoring via current-sense resistor (GPIO 34)  
- 🧠 Automatic charging control using **PWM** output (GPIO 25)  
- 🔄 Stops charging when voltage exceeds a defined threshold (e.g. 3.84V)  
- 📟 Outputs all measurements and status messages via Serial  

---

## 🛠 Hardware Setup

| Component                  | Description                                       |
|---------------------------|---------------------------------------------------|
| **ESP32**                 | Microcontroller board                             |
| **Li-ion Battery**        | Single cell (max ~4.2V nominal)                   |
| **Voltage Divider**       | 10kΩ (R1) and 2.73kΩ (R2) to scale voltage        |
| **Current Sense Resistor**| 0.1Ω placed in series with battery charging path |
| **NPN Transistor (S9014)**| Used to control charging via PWM to its base     |

### 🔌 Pin Connections

| Function               | ESP32 Pin | Description                          |
|------------------------|-----------|--------------------------------------|
| Battery Voltage Input  | GPIO 35   | Analog read from voltage divider     |
| PWM Output             | GPIO 25   | Controls transistor base             |
| Charging Current Sense | GPIO 34   | Reads voltage drop across shunt      |
| Always-On Pin          | GPIO 26   | Set high to enable system power      |

---

## 📏 Voltage Divider Ratio

```plaintext
R1 = 10.0 kΩ  
R2 = 2.73 kΩ  
Ratio = R2 / (R1 + R2) = 2.73 / (10 + 2.73) ≈ 0.2146
````

This scales the 0–4.2V battery voltage to a safe \~0–0.9V range for the ESP32 ADC (max 3.3V).

---

## 📊 Current Measurement Formula

```plaintext
Voltage across shunt resistor = ADC_value × 3.23V / 4095  
Charging current (mA) = (Voltage drop / 0.1Ω) × 1000
```

---

## 🧪 Sample Output (Serial Monitor)

```plaintext
Battery Voltage: 3.77 V, Charging Current: 118.56 mA  
Battery is charging...  
...  
Battery Voltage: 3.85 V, Charging Current: 0.00 mA  
Battery is fully charged. Stop charging.
```

---

## 📁 File Structure

```plaintext
esp32-battery-monitor/
├── src/
│   └── battery_dad/
│       └── battery_dad.ino     # Main Arduino sketch
├── README.md                   # Project documentation
├── .gitignore                  # Git ignore rules
└── LICENSE                     # MIT License
```

---

## 📜 License

This project is licensed under the MIT License – free to use, modify, and share.

---

## 👤 Author

Developed by **Yu Tse Wu**
GitHub: [@Yu-Tse](https://github.com/Yu-Tse)
