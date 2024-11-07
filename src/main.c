#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>

static const struct pwm_dt_spec pwm_led0 = PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0));

#define MIN_PERIOD PWM_SEC(1U) / 128U
#define MAX_PERIOD PWM_SEC(1U)

int main(void)
{
    if(!device_is_ready(pwm_led0.dev)){
        printk("Error: cihaz %s Pwm patladı",pwm_led0.dev->name);
        return 0;
    }
	int ret;
    while(1) {
        ret=pwm_set_pulse_dt(&pwm_led0,0);
        k_sleep(K_SECONDS(1));
        printk("atıyor\n");
        ret=pwm_set_pulse_dt(&pwm_led0,10000);
        k_sleep(K_SECONDS(1));
    }

	return 0;
}