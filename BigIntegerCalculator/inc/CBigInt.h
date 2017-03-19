
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

    int CBigInt::CompareNoSign(const CBigInt& value1, const CBigInt& value2);

	//符号位，0表示正数，1表示负数
	unsigned int m_Sign;
	//大数在x1000000000进制下的数字位数
	unsigned m_nLength;
	//ongoing数组记录大数在x1000000000进制下的每一位的值
	unsigned long m_ulValue[MAX_BI_LEN];
};