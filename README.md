# 📏 DistoMatic — Ultrasonik Mesafe Ölçer

Arduino Uno R4 + HC-SR04 ultrasonik sensör + I2C LCD ekran kullanılarak geliştirilmiş, butona basınca mesafe ölçen ve LCD'de gösteren gömülü sistem projesi.

## 📸 Proje Fotoğrafları

| Bekleme Ekranı | Ölçüm Ekranı |
|----------------|--------------|
| ![](Lab-3%20(1).jpg) | ![](Lab-3%20(4).jpg) |

## 🔧 Donanım

| Bileşen | Detay |
|---------|-------|
| Mikrodenetleyici | Arduino Uno R4 WiFi |
| Mesafe Sensörü | HC-SR04 Ultrasonik |
| Ekran | 16x2 I2C LCD (0x27) |
| Giriş | Push Button |
| Haberleşme | I2C (Wire) |

## 📌 Pin Bağlantıları

| Pin | Bileşen |
|-----|---------|
| D2 | Buton (INPUT_PULLUP) |
| D3 | HC-SR04 TRIG |
| D4 | HC-SR04 ECHO |
| SDA/SCL | LCD I2C |

## ⚙️ Çalışma Mantığı
1. Açılışta LCD'de **"DistoMatic / Butona Basın"** gösterilir
2. Butona basıldığında **"Ölçüyor..."** yazısı çıkar
3. HC-SR04 ultrasonik sinyal gönderir, geri dönüş süresi ölçülür
4. Mesafe hesaplanır: `distance = (pingTime × 0.034) / 2`
5. LCD'de **"Mesafe: XX.X cm"** olarak gösterilir
6. 5 saniye sonra bekleme ekranına döner

## 📁 Dosyalar

| Dosya | Açıklama |
|-------|----------|
| `Oled_hyd_copy_20260310151506/Oled_hyd_copy_20260310151506.ino` | Arduino kaynak kodu |
| `Lab-3 (1-5).jpg` | Proje fotoğrafları |

## 🛠️ Kullanılan Kütüphaneler
- `Wire.h` — I2C haberleşme
- `LiquidCrystal_I2C.h` — LCD kontrolü

## 📚 Ders Bilgisi
**EE304 — Embedded Systems  |  Lab 3**

## 👩‍💻 Geliştirici
**Beyza Erdem** — 2211051049
