#ifndef SAINTMATHEMATICS_VECOTR_H
#define SAINTMATHEMATICS_VECOTR_H

//class Iterator;
#include <cstring>
#include <cassert>

namespace Algorithm
{
	template<typename T>
	class Vector
	{
	private:
		static const int DEFAULTCAPACITY;

	public:
		Vector();
		Vector(const Vector& that);
		~Vector();

		bool Add(const T& element);
		bool Remove(const T& element);
        void Replace(const T*const content,unsigned int size);
        bool Clear();

		int IndexOf(T element)const;
		int Count()const;
		int Capacity()const;

        bool IsExist(const T& element)const;

		T& operator[](int index);
		const T& operator[](int index)const;
		Vector<T>& operator=(const Vector& rhs);

		//For Algorithm
		//bool Swap(const int lhs, const int rhs);
		T* Begin();
        const T* Begin()const;
        T* End();
        const T* End()const;

	protected:
		bool IsCapacityEnough();
		T* m_content;
		int m_count;
		int m_capacity;

	private:
		bool Initialize(int size);
		bool Reallocation();
        bool InternalReplace(const T*const content, unsigned int size);
        bool Destory();
	};

	template<typename T>
	const int Vector<T>::DEFAULTCAPACITY = 1;

	template<typename T>
	Vector<T>::Vector()
	{
		m_content = nullptr;
		m_count = 0;
		m_capacity = 0;
		Initialize(DEFAULTCAPACITY);
	}

    template<typename T>
    Vector<T>::Vector(const Vector& that)
    {
        Initialize(that.Capacity());
        InternalReplace(that.m_content, that.m_count);
    }

	template<typename T>
	Vector<T>::~Vector()
	{
		Destory();
	}

	template<typename T>
	bool Vector<T>::Initialize(int size)
	{
		assert(size > 0);

		m_capacity = size;
		m_count = 0;
		m_content = new T[m_capacity];
		return true;
	}

    template<typename T>
    bool Algorithm::Vector<T>::Clear()
    {
        //for (int i = 0; i < m_count; i++)
        //{
        //    m_content[i];
        //}
        m_count = 0;
        return true;
    }

	template<typename T>
	bool Vector<T>::Add(const T & element)
	{
		if (IsCapacityEnough() == false) {
			Reallocation();
		}
		m_content[m_count] = element;
		m_count++;
		return true;
	}

	template<typename T>
	bool Vector<T>::Remove(const T & element)
	{
		for (int i = m_count - 1; i >= 0; i--)
		{
			if (m_content[i] == element) 
            {
				m_content[i] = nullptr;
				for (int j = i; j < m_count - 1; j++)
				{
					m_content[j] = m_content[j + 1];
				}
				m_content[m_count - 1] = nullptr;
				m_count--;
			}
		}
		return true;
	}

    template<typename T>
    void Algorithm::Vector<T>::Replace(const T*const content, unsigned int size)
    {
        if (m_capacity <= size)
        {
            Clear();
            Initialize(size);
        }
        InternalReplace(content, size);
    }

	template<typename T>
	int Vector<T>::IndexOf(T element)const
	{
		if (m_count == 0) return -1;
		for (int i = m_count - 1; i >= 0; i--)
		{
			if (m_content[i] == element) {
				return i;
			}
		}
		return -1;
	}

	template<typename T>
	inline int Vector<T>::Count()const
	{
		return m_count;
	}

	template<typename T>
	inline int Vector<T>::Capacity()const
	{
		return m_capacity;
	}

    template<typename T>
    bool Algorithm::Vector<T>::IsExist(const T& element) const
    {
        for (int i = 0; i< Count(); i++ )
        {
            if (m_content[i] == element)
            {
                return true;
            }
        }
        return false;
    }

	template<typename T>
	inline T& Vector<T>::operator[](int index)
	{
        return const_cast<T&>(static_cast<const Vector<T>&>(*this)[index]);
	}

	template<typename T>
	inline const T& Vector<T>::operator[](int index) const
	{
        assert(index >= 0 && index < m_count);
		return m_content[index];
	}

	template<typename T>
	inline Vector<T>& Vector<T>::operator=(const Vector& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		Destory();
		Initialize(rhs.Capacity());
		InternalReplace(rhs.m_content, rhs.m_count);
		return *this;
	}
    
    template<typename T>
    const T* Vector<T>::Begin()const
    {
        return m_content;
    }

    template<typename T>
    T*  Vector<T>::Begin()
    {
        return const_cast<T*>(static_cast<const Vector<T>&>(*this).Begin());
    }
    
    template<typename T>
    const T* Vector<T>::End()const
    {
        if (m_count == 0)
        {
            return nullptr;
        }
        return &(m_content[m_count - 1]);
    }

    template<typename T>
    T* Vector<T>::End()
    {
        return const_cast<T*>(static_cast<const Vector<T>&>(*this).End());
    }

	template<typename T>
	bool Vector<T>::IsCapacityEnough()
	{
		return m_count < m_capacity;
	}

	template<typename T>
	bool Vector<T>::Reallocation()
	{
		if (m_capacity == 0)
		{
			return false;
		}
		m_capacity = 2 * m_capacity;
		T* newContent = new T[m_capacity];
		for (int i = 0; i < m_count; i++)
		{
			newContent[i] = m_content[i];
		}
		delete[] m_content;
		m_content = newContent;
		return true;
	}

    template<typename T>
    bool Algorithm::Vector<T>::InternalReplace(const T*const content, unsigned int size)
    {
        memcpy(m_content, content, size);
        m_count = size;
        return true;
    }

    template<typename T>
    bool Vector<T>::Destory()
    {
        if (m_content)
        {
            Clear();
            delete[] m_content;
            m_content = nullptr;
        }
        return true;
    }
}


#endif