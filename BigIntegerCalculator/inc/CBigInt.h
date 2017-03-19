
#define MAX_BI_LEN 10

class CBigInt{
public:

	CBigInt(){};
	~CBigInt(){};

	void Add(const CBigInt& value1, const CBigInt& value2, CBigInt& result);
	//CBigInt operator+(const CBigInt& value) const;
    CBigInt operator+(const CBigInt& value);

	void Sub(const CBigInt& value1, const CBigInt& value2, CBigInt& result);
	//CBigInt operator-(const CBigInt& value) const;
    CBigInt operator-(const CBigInt& value);

    void Mul(const CBigInt& value1, const CBigInt& value2, CBigInt& result);

    void Div(const CBigInt& value1, const CBigInt& value2, CBigInt& result);

    void Power(const CBigInt& value1, const CBigInt& value2, CBigInt& result);

    int CompareNoSign(const CBigInt& value1, const CBigInt& value2);

	//����λ��0��ʾ������1��ʾ����
	unsigned int m_Sign;
	//������x1000000000�����µ�����λ��
	unsigned m_nLength;
	//ongoing�����¼������x1000000000�����µ�ÿһλ��ֵ
	unsigned long m_ulValue[MAX_BI_LEN];
};