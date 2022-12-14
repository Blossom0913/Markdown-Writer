# CPU工作原理00

### MOSFET[^1]

1. 二极管原理
纯硅单个硅原子会和周围的4个硅原子形成稳定的共价键

    - （N型掺杂）如果在Si中掺入少量P（最外层电子数 = 5）则会多出一个自由电子[^2]
    -  (P型掺杂）如果在Si中掺入少量B（最外层电子数 = 3）则会少一个电子，形成一个空位
![NMOS](/NMOS.png)
  ---
1. 把一个N型半导体和P型半导体连在一起，就会得到一个**PN结**。
   - 在PN结的中部，由于电子的扩散作用（类似于水分子扩散），P中e向N移动，中间一部分的区域因而形成了P->N的电场，成为**耗尽层**，阻碍了e的扩散，但如果此时外界施加一个足够大的电场，就可以**导通**PN结。
  ![耗尽层](/%E8%80%97%E5%B0%BD%E5%B1%82.png)
   - 但如果施加的是**反向**的电场，会把电子往右边赶，导致耗尽层扩大，**不导通**。
  ---
3. 利用上述特性，我们就可以构造如图的**MOSFET**
   - 如图的NMOS装置由两个N区域和一个P区域组成，分别在N区域处接上电源，分析得知，电源无法导通，但是，我们在MOS的栅极（Gate）处和MOS的底部接上控制电路，在施加**高电压**的时候，受到**场效应**[^3]的作用，电子向上运动，因而导致栅极附近的P区域转变成N区域沟道，导致NMOS导通。到此我们得到了一个控制电压＞阈值电压就导通的元器件。
   - PMOS刚好与NMOS相反，由两个P区域和一个N区域组成，如果输入高电压，就会导致不导通，如果输入低电压，则会导致导通。
   - 把PMOS和NMOS的**漏极（Drain**连接，然后PMOS的**源极（Source**连接高电平（VDD），NMOS的源极连接低电平（VSS），这就组成了一个CMOS，逻辑电路中最简单的单元——**非门电路**
   - 非门电路的特点即A端输入高电压，B端输出低电压；A端输入低电压，B端输出高电压。
  ![CMOS](/%E9%9D%9E%E9%97%A8%E7%94%B5%E8%B7%AF.png)






[^1]:金属氧化物场效应晶体管
[^2]:**载流子**
[^3]:电场效应