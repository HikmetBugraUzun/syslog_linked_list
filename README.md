Linux Syslog Linked List

Bu program, Linux işletim sistemindeki syslog kayıtlarını okuyarak bir bağlı liste (linked list) veri yapısı içinde saklar ve görüntüler.

📌 Kullanılan Teknolojiler

C Programlama Dili

Bağlı Liste (Linked List) Kullanımı

Dosya İşlemleri (fopen, fgets, fclose)

Dinamik Bellek Yönetimi (malloc, free)

🚀 Programın Amacı

/var/log/syslog dosyasını okuyarak sistem loglarını bir bağlı liste içinde saklar.

Logları dinamik olarak işler ve terminalde görüntüler.

Bağlı liste yapısını kullanarak belleği verimli yönetir.

🔧 Kurulum ve Çalıştırma

Programı derlemek için:

gcc syslog_reader.c -o syslog_reader

Programı çalıştırmak için: (Yetki gerektirdiği için sudo ile çalıştırmalısın)

sudo ./syslog_reader

📂 Proje Yapısı

📦 syslog_linked_list
 ┣ 📜 syslog_reader.c  # Ana C programı
 ┣ 📜 README.md        # Proje açıklaması

 Bağlı Liste Kullanım Sebebi

Syslog kayıtları dinamik olarak büyüyüp küçülebilen bir yapıya sahiptir. Bu nedenle bağlı liste tercih edilmiştir:

Bellek verimli kullanılır.

Yeni loglar eklenebilir ve sıralı şekilde işlenebilir.

Gelecekte filtreleme gibi ek işlemler için esneklik sağlar.

Not: Log dosyalarına erişim için sudo yetkisi gerekebilir. Kullanıcı izinleri ile ilgili problemler yaşarsanız, /var/log/syslog dosyasına okuma izni vermeniz gerekebilir.
