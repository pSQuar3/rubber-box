terms_count = input('enter the number of terms to be fit using DFT ');
terms = input('enter the terms to be fit using DFT in the format [x1,x2,x3,...]');
N = terms_count/2;
t = zeros(terms_count,1);
w = zeros(terms_count,1);
T = 2*(pi);
exp_matrix = zeros(terms_count,terms_count);
f = zeros(terms_count);
for i=1:terms_count
    t(i) = ((i-1)*(pi))/N;
    w(i) = (i-1);
end
for i=1:terms_count
    for j=1:terms_count
        exp_matrix(i,j) = exp((1i)*w(i)*t(j));
    end
end
F = (1/(2*N)) * (exp_matrix) * (terms');
ans_DFT = ['The DFT fitted equation is f(tk)='];
if real(F(1)) >= 0.01 || real(F(1)) <= -0.01
    if imag(F(1)) >= 0.01 || imag(F(1)) <= -0.01
        ans_DFT = cat(2,ans_DFT,[num2str(real(F(1))),'+i',num2str(imag(F(1)))]);
    end
end
if real(F(1)) >= 0.01 || real(F(1)) <= -0.01
    if imag(F(1)) <= 0.01 && imag(F(1)) >= -0.01
        ans_DFT = cat(2,ans_DFT,[num2str(real(F(1)))]);
    end
end
if real(F(i)) <= 0.01 && real(F(i)) >= -0.01
    if imag(F(1)) >= 0.01 || imag(F(1)) <= -0.01
        ans_DFT = cat(2,ans_DFT,['+i',num2str(imag(F(1)))]);
    end
end
for i=2:terms_count
    if real(F(i)) >= 0.01 || real(F(i)) <= -0.01
        if imag(F(i)) >= 0.01 || imag(F(i)) <= -0.01
            ans_DFT = cat(2,ans_DFT,['+',num2str(real(F(i))),'+i',num2str(imag(F(i))),'exp(-i',num2str(i-1),'tk)']);
        end
    end
    if real(F(i)) >= 0.01 || real(F(i)) <= -0.01
        if imag(F(i)) <= 0.01 && imag(F(i)) >= -0.01
            ans_DFT = cat(2,ans_DFT,['+',num2str(real(F(i))),'exp(-i',num2str(i-1),'tk)']);
        end
    end
    if real(F(i)) <= 0.01 && real(F(i)) >= -0.01
        if imag(F(i)) >= 0.01 || imag(F(i)) <= -0.01
            ans_DFT = cat(2,ans_DFT,['+i',num2str(imag(F(i))),'exp(-i',num2str(i-1),'tk)']);
        end
    end
end
disp(ans_DFT);
