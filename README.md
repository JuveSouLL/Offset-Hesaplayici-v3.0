🧮 Offset Hesaplayıcı v3.0

Bu proje, çeşitli oyun içi bellek adreslerine (offset'lere) göre temel saldırı hızı (saldiri_hizi) değerini hesaplayan ve bu değere bağlı diğer offset'leri otomatik olarak türeten bir Windows GUI uygulamasıdır. Özellikle oyun içi cheat/debug işlemleri ile uğraşan geliştiricilere veya analizcilere yöneliktir.

<!-- Ekran görüntüsü eklerseniz bu alanı güncelleyebilirsiniz -->

🚀 Özellikler

Hex (0x1E1C) veya decimal (7708) formatında offset girişi desteği

Seçilen offset türüne göre otomatik saldırı hızı hesabı

Tüm ilgili offset'leri sabit formüllerle hesaplayarak listeleme

Hem hexadecimal hem decimal çıktı formatı

Sade, okunabilir ve genişletilebilir arayüz (MemoBox ile detaylı çıktı)

Modern ve profesyonel C++ Builder VCL tasarımı

📐 Offset Hesaplama Mantığı

Girdi olarak bir offset (örneğin wallhack, vid, hareket_hizi) seçilir ve değeri girilir. Uygulama, seçilen offset'e göre saldırı hızı (saldiri_hizi) değerini şu formüllerle hesaplar:

Offset Adı	Hesaplama Formülü
wallhack	saldiri_hizi = offset - 0xCA

vid	saldiri_hizi = offset - 0xC6

hareket_hizi	saldiri_hizi = offset - 0x4

silah_uzunlugu	saldiri_hizi = offset - 0x8

player_x/y/z	saldiri_hizi = offset - 0x36/32/2E

one_hit	saldiri_hizi = offset - 0xAA

ktype	saldiri_hizi = offset - 0xA6

isdead	saldiri_hizi = offset - 0x5A

weapon type	saldiri_hizi = offset - 0x16E

saldiri_hizi	saldiri_hizi = offset

🖥️ Kullanım

Proje açıldığında, form üzerinde bir offset seçin (ComboBox1).

Hex (0x1E1C) ya da decimal (7708) formatında bir değer girin.

“Hesapla” butonuna basın.

Aşağıdaki Memo kutusunda tüm hesaplanan offset'ler ve detaylı açıklamalar listelenecektir.

📂 Dosya Yapısı

Unit1.cpp: Ana iş mantığını içeren dosya

Unit1.h: Header tanımlamaları

.dfm: Görsel bileşenlerin form ayarları

IntToHex() ve HesaplaSaldiriHizi() gibi işlevler ile mantıksal yapı net ve anlaşılır tutulmuştur

🧩 Genişletilebilirlik

Uygulama tasarımı sade ve modülerdir. Yeni offset türleri ya da farklı hesaplama yöntemleri kolayca HesaplaSaldiriHizi() fonksiyonuna eklenebilir. Ayrıca mevcut GUI bileşenleri (ComboBox, Memo, Edit) yeni işlemler için yeniden kullanılabilir.

🛠️ Gereksinimler
C++ Builder / RAD Studio

VCL proje türü

Windows işletim sistemi (Win32/Win64)

📃 Lisans
Bu proje açık kaynaklıdır. Lisans koşullarını LICENSE dosyasından kontrol edebilirsiniz.

✍️ Geliştirici

JuveSouL

📧 Discord : juvesoul

💬 "Analiz, hesaplama ve oyun içi araçlar geliştirmenin keyfi, verimli kodlarla daha da artar."
