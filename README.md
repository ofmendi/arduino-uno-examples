# Microcontroller sample questions and solutions.
----

1.
• Seri porttan “Program başladı” yazısı gönderilecektir.
• Bağlı bir buton dış kesme alacak şekilde ayarlanacaktır.
• Butona 1 sn içinde 3 kez üst üste tıklanana (3 kez kesme alana) kadar işlem yapılmayacaktır.
• Bundan sonra potansiyometreden değer okunarak, değerin gerilim karşılığı seri porttan gönderilecektir.
• Potansiyometre’den okunan değere göre DC motor hız (devir/dk) kontrolü yapılacaktır.

2.
• 74HC73 JK Flip Flop etnegre devreleri kullanılarak 4 bitlik shift register tasarlanacaktır.
• Shift Registerin veri girişi ve clock sinyali arduino ile verilecektir.
• Seri porttan gelen 1 hanelik hexadecimal değer saniyede 1 bit olmak üzere sırasıyla shift registera girilecektir.
• Shift register çıkışlarına bağlı LED’lerden register içeriği görülebilecektir.

3.
• Seri porttan “Program başladı” yazısı gönderilecektir.
• Bağlı bir butona 0.5 sn içinde 2 kez üst üste tıklanana kadar beklenecektir.
• Bundan sonra potansiyometreden değer okunarak, değerin gerilim karşılığı seri porttan gönderilecektir.
• Potansiyometre’den okunan değere göre servo motorun açı kontrolü 0~180 derece arasında yapılacaktır.

4.
• Seri porttan “Program başladı” yazısı gönderilecektir.
• Bundan sonra seri porttan “BASLA” komutu gönderilmesi beklenecektir.
• 4 ayrı girişte bağlı anahtarlardan (switch) alınacak veri ile elde edilecek 1 nibble’lık verinin decimal karşılığı
seri porttan gönderilecektir.
• Bu veriye göre servo motorun açı kontrolü 0~180 derece arasında yapılacaktır.

5.
• Seri porttan “Program başladı” yazısı gönderilecektir.
• Bundan sonra seri porttan “BASLA” komutu gönderilmesi beklenecektir.
• Komut geldikten sonra, bağlı butona basıldığında dış kesme ile ISR alt programında LM25 sıcaklık
sensöründen veri okunacaktır.
• Okunan veri aşağıdaki formatta seri porttan gönderilecektir.
  ◦ Sicaklik : 15 C , Onceki olcumden 1 C daha yuksek

6.
• Seri porttan “Program başladı” yazısı gönderilecektir.
• Bundan sonra seri porttan “BASLA” komutu gönderilmesi beklenecektir.
• Bağlı olan bir LDR ve 270 ohm direnç ile oluşturulacak gerilim bölücü üzerinden, LDR’nin üzerinde düşen
gerilim miktarı okunacaktır.
•
Veri değerlendirilerek aşağıdaki formatta seri porttan bilgi gönderilecektir.
  ◦ LDR Gerilimi : X.00 V , LDR Direnci = XXX ohm

7.
• Seri porttan “Program başladı” yazısı gönderilecektir.
• Bundan sonra seri porttan “BASLA” komutu gönderilmesi beklenecektir.
• 8 ayrı girişte bağlı anahtarlardan (switch) alınacak veri ile elde edilecek 1 byte’lık verinin decimal karşılığı seri
porttan gönderilecektir.
• Bu veriye göre DC motor hız (devir/dk) kontrolü yapılacaktır.

8.
• Analog girişlere bağlı iki buton bulunacaktır.
• Çıkışlara bağlı 2 adet 7 segment display onlar ve birler basamağını gösterecek şekilde bağlanacaktır.
• Analog girişe bağlı butonlardan birine basılı tutulduğu sürece 2 haneli 7 segment display’de her 0.5sn’de bir
ileri yönde sayma işlemi yapılacaktır.
• İlk buton bırakılıp, diğer basılı tutulduğunda da aynı şekilde geri sayma işlemi yapılacaktır.
(intermediate) Microcontroller sample questions and solutions.
