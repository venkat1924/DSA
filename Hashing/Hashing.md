# Hashing
- Hashing is the process of mapping large amounts of data into a smaller value using a hash function.
- The table which stores the data is called a hash table.
- To convert the data (keys) into a hash value, we use the hash function.
- If `x` denotes the data (key) to be stored, we can say that `h(x)` denotes the hashed value, where h is the hash function.
- Different types of hash functions are
  - Division method
  - Multiplication method
  - Mid-square method

## Division method
  <p align="center">
    $h(x)=x \pmod m$ 
  </p>
  
where $m$ is the size of the hash table.

For example:
Let the size of the hash table be `m = 7` and the `keys = {52, 44, 35, 24, 10}`


  
 $h(52)=52 \pmod 7 =3$
  
  $h(44)=44 \pmod 7 =2$
  
  $h(35)=35 \pmod 7 =0$
  
  $h(24)=24 \pmod 7 =3$
  
  $h(10)=10 \pmod 7 =3$
  

  
The hash table will look like:

<div align="center">
  
  |Index|Value|
  |---|---|
  |0|35|
  |1| |
  |2| 44|
  |3|52, 24, 7|
  |4| |
  |5| |
  |6| |
  
</div>

## Collision

>[!IMPORTANT]
>**Collision**: the hash value generated by the hash function is the same for two different keys.

Two methods of avoiding collision:
- Open Addressing
  - Linear probing
  - Quadratic probing
  - Double hashing
- Separate Chaining

### Open Addressing (aka) Closed Hashing
#### Linear Probing
Let `m=10`, then:

<div align="center">
  
$h(x)=x \pmod {10} $

</div>  

Let `keys={12, 44, 67, 22, 58, 64, 52, 89}`

We can instead define $h(x)$ to be:

<div align="center">
  
$h(x)=(h(x)+i) \mod {10}$ <br>
  where i=0, 1 ... 9
  
</div>

$h(12)=2+0 \pmod {10}=2$

$h(44)=4+0 \pmod {10}=4$

$h(67)=7+0\pmod {10}=7$

$h(22)=2+0\pmod {10}=2$ which causes a collision. So we increment `i`. Now, $h(22)=2+1\pmod {10}=3$

$h(58)=8+0\pmod {10}=8$

$h(64)=4+0\pmod {10}=4$ which causes a collision. So we increment `i`. Now $h(64)=4+1\pmod {10}=5$

$h(52)=2+0\pmod {10}=2$ which causes a collision. So we increment `i`. Now $h(52)=2+1\pmod {10}=3$ which again causes a collision. So we again increment `i`. Now $h(52)=2+2\pmod {10}=4$ which is a collision; increment `i`. Now $h(52)=2+3\pmod {10}=5$ which is a collision; increment `i`. Now $h(52)=2+4\pmod {10}=6$.

$h(89)=9+0\pmod {10}=9$


The hash table will look like:

<div align="center">

|Index|Value|
| :---:| :---:|
|0| |
|1| |
|2|12|
|3|22|
|4|44|
|5|64|
|6|52|
|7|67|
|8|58|
|9|89|

</div>

The **problem** with linear probing is that it forms **clusters**.

#### Quadratic Probing

Let `m=10`, then:

<div align="center">
  
$h(x)=x \pmod {10}$

</div>  

Let `keys={52, 24, 72, 80, 44, 65, 64}`.

We can instead define $h(x)$ to be:

<div align="center">
  
$h(x)=(h(x)+i^2) \mod {10}$ <br>
  where i=0, 1 ... 9
</div> 

$h(52)=2+0\pmod {10}=2$

$h(24)=4+0\pmod {10}=4$

$h(72)=2+0\pmod {10}=2$ causes collision, increment and square i. $h(72)=2+1^2\pmod {10}=3$.

$h(80)=0+0\pmod {10}=0$

$h(44)=4+0\pmod {10}=4$ causes a collision, increment and square i. $h(44)=4+1^2\pmod {10}=5$.

$h(65)=5+0\pmod {10}=5$ causes a collision, increment and square i. $h(65)=5+1^2\pmod {10}=6$.

$h(64)=4+0\pmod {10}=4$ causes a collision, increment and square i. $(64)=4+1^2\pmod {10}=5$ causes a collision, increment and square i. $h(64)=4+2^2\pmod {10}=8$.

<div align="center">

|Index|Value|
| :---:| :---:|
|0|80|
|1| |
|2|52|
|3|72|
|4|24|
|5|44|
|6|65|
|7||
|8|64|
|9||

</div>

#### Double hashing

<p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures_and_Applications/assets/128356330/30259cf7-9129-4a38-b476-bc15ea2a70c9" width=400>
</p>

That was a bad second hash function, a good one should never evaluate to zero and should allow you to probe every cell in the hash table.

### Separate Chaining

<p align="center">
  <img src="https://github.com/venkat1924/IS233AI-Data_Structures_and_Applications/assets/128356330/bce29021-c741-4968-b40e-2442ee8d65ad" width=400>
</p>



