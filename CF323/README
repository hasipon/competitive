Cdiv1
(l, s)を固定して考える
subarrayにa[i]が含まれるならば、
i ≡ j mod gcd(n,s)となるすべてのjについてa[i] >= a[j]である

gcd(n,s)を固定し、それをgとする。gはnの約数である
各0 <= r < gについて m[r] = max_{i≡r mod g} a[i]を計算する。
subarrayにa[i]が含まれるならば、a[i] = m[i % g]でなくてはならない。
あとはこの条件を満たす区間について数え上げる。
