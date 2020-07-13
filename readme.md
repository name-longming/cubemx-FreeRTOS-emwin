[![](https://img.shields.io/github/stars/name-longming/cubemx-FreeRTOS-emwin.svg?style=social&label=Star)](https://github.com/name-longming/EmWin-SmallPhone)[![](https://img.shields.io/github/forks/name-longming/cubemx-FreeRTOS-emwin.svg?style=social&label=Fork)](https://github.com/name-longming/EmWin-SmallPhone)

# 在cubemx环境下移植了FreeRTOS+emwin（含触摸）

这个移植有多麻烦就不用我细说了......着实有很多很多很多的坑（懂的都懂）。

## 🔨使用器件

stm32F407+ILI93412.8寸电阻屏

## 📄实验版本

含emwin无操作系统固件库版本（含触摸），hal库emwin+FreeRTOS（静态搭建，含触摸）版本和hal库emwin+FreeRTOS（动态搭建，含触摸）版本，所有版本都自带一个官方demo（用于检测是否移植正确）

## ✅实现效果

![EMWIN](https://img-blog.csdnimg.cn/20200630181005259.JPG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25hbWVfbG9uZ21pbmc=,size_16,color_FFFFFF,t_70)

## 📄更新日志

| 更新时间  |                       更新时间                       |
| :-------: | :--------------------------------------------------: |
| 2020.7.13 |        修复emwin（5.40版本）触摸鼠标错位问题         |
| 2020.7.4  | 增加了HAL版emwin（5.40版本）+FreeRTOS和库函数版emwin |
| 2020.6.30 |       增加了HAL版emwin+FreeRTOS和库函数版emwin       |