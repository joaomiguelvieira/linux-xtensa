obj-$(CONFIG_ESP32_WIFI)		+= esp32-wifi.o
esp32-wifi-objs				+= main.o esp_cmd.o esp_wpa_utils.o esp_cfg80211.o esp_stats.o
esp32-wifi-$(CONFIG_ESP32_BT)		+= esp_bt.o
esp32-wifi-$(CONFIG_ESP32_WIFI_SPI)	+= esp_spi.o
esp32-wifi-$(CONFIG_ESP32_WIFI_SDIO)	+= esp_sdio.o
esp32-wifi-$(CONFIG_ESP32_WIFI_SHMEM)	+= esp_shmem.o
esp32-wifi-objs				+= $(esp32-wifi-m)
