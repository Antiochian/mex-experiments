%speed test!

N = 100000000

fprintf("Using inbuilt:\n");
t0 = cputime;

out1 = count_primes(N);

fprintf("Time taken: ");
fprintf('%f',cputime-t0);
fprintf(" seconds \n");

fprintf("Using MEX:\n");
t0 = cputime;

out2 = sieve(N);

fprintf("Time taken: ");
fprintf('%f',cputime-t0);
fprintf(" seconds \n");
% N = 10000000
% inputs = (1000)*rand(N,1); 
% 
% out1 = [];
% out2 = [];
% fprintf("Using inbuilt:\n");
% t0 = cputime;
% 
% out1 = sqrt(inputs);
% 
% fprintf("Time taken: ");
% fprintf('%f',cputime-t0);
% fprintf(" seconds \n");
% 
% fprintf("Using MEX:\n");
% t0 = cputime;
% 
% out2 = mex_test(inputs);
% 
% fprintf("Time taken: ");
% fprintf('%f',cputime-t0);
% fprintf(" seconds \n");
