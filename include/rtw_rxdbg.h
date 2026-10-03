/******************************************************************************
 * [W4-fix probe] temporary RX-path instrumentation (remove before ship)
 * SPDX-License-Identifier: GPL-2.0
 ******************************************************************************/
#ifndef _RTW_RXDBG_H_
#define _RTW_RXDBG_H_

#include <drv_types.h>

void rtw_rxdbg_frame(struct rx_pkt_attrib *pattrib, u8 *pbuf, s32 transfer_len,
		     int it);
void rtw_rxdbg_badoff(struct rx_pkt_attrib *pattrib, u8 *pbuf, s32 transfer_len);
void rtw_rxdbg_alloc(union recv_frame *prf, u8 *pdata, int ok);
void rtw_rxdbg_conv_in(union recv_frame *prf);
void rtw_rxdbg_conv_out(union recv_frame *prf, int rmv_len, int bsnaphdr,
			int pull_sz);
void rtw_rxdbg_ind(union recv_frame *prf, void *skb);
void rtw_rxdbg_readport(int kind, void *skb);
void rtw_rxdbg_comp(int kind, void *pskb, void *precvbuf);
void rtw_rxdbg_fq_in(void);
void rtw_rxdbg_tasklet(int nskb, int rxq_len, int freeq_len, int pendq_len);
void rtw_rxdbg_dump(void);

extern unsigned int rtw_rxdbg_fq_direct_free;
extern unsigned int rtw_rxdbg_frames;
extern unsigned int rtw_rxdbg_eapol;
extern unsigned int rtw_rxdbg_last_comp_ms;
extern unsigned int rtw_rxdbg_last_ok_ms;
extern unsigned int rtw_rxdbg_last_frame_ms;
extern unsigned int rtw_rxdbg_last_ind_ms;

#define RTW_RXDBG_RP_REUSE	1
#define RTW_RXDBG_RP_ALLOC	2
#define RTW_RXDBG_RP_ALLOC_FAIL	3
#define RTW_RXDBG_C_OK		1
#define RTW_RXDBG_C_CANNOT	2
#define RTW_RXDBG_C_STOPPED	3
#define RTW_RXDBG_C_REARM	4
#define RTW_RXDBG_C_OTHER	5
#define RTW_RXDBG_C_SUBFAIL	6
#define RTW_RXDBG_C_BADLEN	7

#endif /* _RTW_RXDBG_H_ */
