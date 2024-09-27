# 系统定时器（SysTick Timer）

## SysTick功能框图

![SysTick功能框图](C:\Users\xiech\AppData\Roaming\Typora\typora-user-images\image-20240926162203729.png)

​		counter在时钟的驱动下，从reload初值开始往下递减计数到0，产生中断中断，和置位COUNTFLAG标志，然后从reload值重新递减计数，如此循环。

## 相关寄存器

![控制及状态寄存器（CTRL）](C:\Users\xiech\AppData\Roaming\Typora\typora-user-images\image-20240926162610959.png)

```c
typedef struct
{
  __IO uint32_t CTRL;                         /*!< Offset: 0x00  SysTick Control and Status Register */
  __IO uint32_t LOAD;                         /*!< Offset: 0x04  SysTick Reload Value Register       */
  __IO uint32_t VAL;                          /*!< Offset: 0x08  SysTick Current Value Register      */
  __I  uint32_t CALIB;                        /*!< Offset: 0x0C  SysTick Calibration Register        */
} SysTick_Type;
```

```c
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
    // 判断 tick 的值是否大于 2^24, 如果大于不符合规则，返回 1
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */
     // 设置系统时钟的 重装载值                                                          
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
    // 配置成内核外设的最低优先级   1 << 4 - 1s
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
    //设置 sysTic
  SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}
```

