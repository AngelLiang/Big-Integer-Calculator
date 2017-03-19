#include "CBigInt.h"

/*
 * 函数：CompareNoSign
 * 参数：const CBigInt& value1 - 比较数1
 *       const CBigInt& value2 - 比较数2
 * 返回：int
 */
int CBigInt::CompareNoSign(const CBigInt& value1, const CBigInt& value2)
{
    int result = 0;
    if (value1.m_nLength != value2.m_nLength){
        result = (int)(value1.m_nLength - value2.m_nLength);
    }
    else{
        for (int i = value1.m_nLength - 1; i > 0; i--){
            if (value1.m_ulValue[i] != value2.m_ulValue[i]){
                result = (int)(value1.m_ulValue[i] - value2.m_ulValue[i]);
            }
        }
    }
    return result;
}

/*
 * 函数：Add
 * 参数：const CBigInt& value1 - 被加数
 *       const CBigInt& value2 - 加数
 *       CBigInt& result - 结果
 * 返回：void
 */
void CBigInt::Add(const CBigInt& value1, const CBigInt& value2, CBigInt& result)
{
	result = value1;

	unsigned carry = 0;
	//调整位数对齐
	if (result.m_nLength < value2.m_nLength){
		result.m_nLength = value2.m_nLength;
	}

	for (unsigned int i = 0; i < result.m_nLength; i++){
		unsigned __int64 sum = value2.m_ulValue[i];
		sum = sum + result.m_ulValue[i] + carry;
		result.m_ulValue[i] = (unsigned long)sum;
		carry = (unsigned)(sum >> 32);	//获取符号位
	}
	//处理最高位，如果当前最高位进制carry!=0，则需要增加大数的位数
	result.m_ulValue[result.m_nLength] = carry;
	result.m_nLength += carry;
}

/*
 * 函数：operator+
 * 参数：const CBigInt& value
 * 返回：CBigInt
 * 说明：重载加号
 */
CBigInt CBigInt::operator+(const CBigInt& value)
{
	CBigInt r;

	if (m_Sign == value.m_Sign){
		CBigInt::Add(*this, value, r);
		r.m_Sign = m_Sign;
	}else{
        if (CompareNoSign(*this, value) >= 0){
			CBigInt::Sub(*this, value, r);
			r.m_Sign = m_Sign;
		}else{
			CBigInt::Sub(value, *this, r);
			r.m_Sign = value.m_Sign;
		}
	}
	return r;
}

/*
 * 函数：Sub
 * 参数：const CBigInt& value1 - 被减数
 *       const CBigInt& value2 - 减数
 *       CBigInt& result - 结果
 * 返回：void
 */
void CBigInt::Sub(const CBigInt& value1, const CBigInt& value2, CBigInt& result)
{
	CBigInt r = value1;

	unsigned int borrow = 0;
	for (unsigned int i = 0; i < r.m_nLength; i++)
	{
		if ((r.m_ulValue[i] > value2.m_ulValue[i])
			|| ((r.m_ulValue[i] == value2.m_ulValue[i]) && (borrow == 0))){
			r.m_ulValue[i] = r.m_ulValue[i] - borrow - value2.m_ulValue[i];
			borrow = 0;
		}else{
			unsigned __int64 num = 0x100000000 + r.m_ulValue[i];
			r.m_ulValue[i] = (unsigned long)(num - borrow - value2.m_ulValue[i]);
			borrow = 1;
		}
	}
	while ((r.m_ulValue[r.m_nLength - 1] == 0) && (r.m_nLength > 1)){
		r.m_nLength--;
	};
	result = r;
}

/*
 * 函数：operator-
 * 参数：const CBigInt& value
 * 返回：CBigInt
 * 说明：重载减号
 */
CBigInt CBigInt::operator-(const CBigInt& value)
{
	CBigInt r;

	if (m_Sign != value.m_Sign){
		CBigInt::Add(*this, value, r);
		r.m_Sign = m_Sign;
	}else{
		if (CompareNoSign(*this, value) >= 0){
			CBigInt::Sub(*this, value, r);
			r.m_Sign = m_Sign;
		}else{
			CBigInt::Sub(value, *this, r);
			r.m_Sign = (m_Sign == 0) ? 1 : 0;
		}
	}
	return r;
}

/*
 * 函数：Mul
 * 参数：const CBigInt& value1 - 乘数1
 *       const CBigInt& value2 - 乘数2
 *       CBigInt& result - 相乘结果
 * 返回：void
 */
void CBigInt::Mul(const CBigInt& value1, const CBigInt& value2, CBigInt& result)
{

}

/*
 * 函数：Div
 * 参数：const CBigInt& value1 - 被除数
 *       const CBigInt& value2 - 除数
 *       CBigInt& result - 结果
 * 返回：void
 */
void CBigInt::Div(const CBigInt& value1, const CBigInt& value2, CBigInt& result)
{

}

/*
 * 函数：Power
 * 参数：const CBigInt& value - 底数
 *       const CBigInt& n - 乘方
 *       CBigInt& result - 结果
 * 返回：void
 */
void CBigInt::Power(const CBigInt& value, const CBigInt& n, CBigInt& result)
{

}