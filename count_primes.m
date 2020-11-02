function [count] = count_primes(n)

primes(1:n+1,1) = true;

p = 2;
while p*p < n
    if primes(p-1)
        i = p*p;
        while i <= n
            primes(i-1) = false;
            i = i+p;
        end
    end
    p = p+1;
end
count = 0;
for i = 2:n
    if primes(i-1)
        count = count + 1;
    end
end

end