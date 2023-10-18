// SPDX-License-Identifier: GPL-2.0-only
/*
 * Espressif Systems Wireless LAN device driver
 *
 * SPDX-FileCopyrightText: 2015-2023 Espressif Systems (Shanghai) CO LTD
 *
 */
#ifndef __esp_cmd_h_
#define __esp_cmd_h_

#include "esp.h"

#define ESP_NUM_OF_CMD_NODES 20
#define ESP_SIZE_OF_CMD_NODE 2048

#define ESP_CMD_HIGH_PRIO    1
#define ESP_CMD_DFLT_PRIO    0

struct multicast_list {
	struct esp_wifi_device *priv;
	u8 addr_count;
	u8 mcast_addr[MAX_MULTICAST_ADDR_COUNT][MAC_ADDR_LEN];
};


int esp_commands_setup(struct esp_adapter *adapter);
int esp_commands_teardown(struct esp_adapter *adapter);
int cmd_init_interface(struct esp_wifi_device *priv);
int cmd_deinit_interface(struct esp_wifi_device *priv);
int process_cmd_resp(struct esp_adapter *adapter, struct sk_buff *skb);
int cmd_scan_request(struct esp_wifi_device *priv,
		struct cfg80211_scan_request *request);
int cmd_get_mac(struct esp_wifi_device *priv);
int cmd_set_mac(struct esp_wifi_device *priv, uint8_t *mac_addr);
int process_cmd_event(struct esp_wifi_device *priv, struct sk_buff *skb);
int cmd_connect_request(struct esp_wifi_device *priv,
		struct cfg80211_connect_params *params);
int cmd_auth_request(struct esp_wifi_device *priv,
		struct cfg80211_auth_request *req);
int cmd_assoc_request(struct esp_wifi_device *priv,
		struct cfg80211_assoc_request *req);
int cmd_disconnect_request(struct esp_wifi_device *priv, u16 reason_code);
int cmd_add_key(struct esp_wifi_device *priv, u8 key_index, bool pairwise,
		const u8 *mac_addr, struct key_params *params);
int cmd_del_key(struct esp_wifi_device *priv, u8 key_index, bool pairwise,
		const u8 *mac_addr);
int cmd_set_default_key(struct esp_wifi_device *priv, u8 key_index);
int cmd_set_ip_address(struct esp_wifi_device *priv, u32 ip);
int cmd_set_mcast_mac_list(struct esp_wifi_device *priv, struct multicast_list *list);
int cmd_set_tx_power(struct esp_wifi_device *priv, int power);
int cmd_get_tx_power(struct esp_wifi_device *priv);
int cmd_set_reg_domain(struct esp_wifi_device *priv);
int cmd_get_reg_domain(struct esp_wifi_device *priv);
#endif
