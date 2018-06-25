#include <iostream>
#include <algorithm>

template <typename Type_>
class vector_t
{
private:
	Type_ * data_;
	std::size_t size_;
	std::size_t capacity_;
public:
	vector_t();
	vector_t(vector_t const & other);
	vector_t & operator =(vector_t const & other);
	~vector_t();

	std::size_t size() const;
	std::size_t capacity() const;

	void push_back(Type_ value);
	void pop_back();

	Type_ & operator [](std::size_t index);
	Type_ operator [](std::size_t index) const;
	
	Type_ & at(std::size_t index);
    	Type_ at(std::size_t index) const;

	bool operator ==(vector_t const & other) const;
};

template <typename Type_>
bool operator !=(vector_t<Type_> const & lhs, vector_t<Type_> const & rhs);

template <typename Type_>
vector_t<Type_>::vector_t()
{
	data_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

template <typename Type_>
vector_t<Type_>::vector_t(vector_t const & other)
{
	data_ = new Type_ [other.capacity_];
	for ( std::size_t i = 0;i < other.size_; i++ ) 
	{
		data_[i] = other.data_[i];
	}
	size_ = other.size_;
	capacity_ = other.capacity_;
}

template <typename Type_>
vector_t<Type_> & vector_t<Type_>::operator =(vector_t const & other)
{
	if  (this != &other)
	{
		if ( data_ != nullptr )
		{
			delete [] data_;
		}
		data_ = new Type_ [other.capacity_];
		for ( std::size_t i = 0;i < other.size_;i++ ) 
		{
			data_[i] = other.data_[i];
		}
		size_ = other.size_;
		capacity_ = other.capacity_;
	}
	return *this;
}

template <typename Type_>
bool vector_t<Type_>::operator ==(vector_t const & other) const
{
	if ( (size_ == other.size_) && (capacity_ == other.capacity_) )
	{
		for ( std::size_t i = 0;i < size_; i++ )
		{
			if ( !( data_[i] == other.data_[i] ) )
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

template <typename Type_>
vector_t<Type_>::~vector_t()
{
	if ( data_ != nullptr )
	{
		delete [] data_;	
	}
}

template <typename Type_>
std::size_t vector_t<Type_>::size() const
{
    return size_;
}

template <typename Type_>
std::size_t vector_t<Type_>::capacity() const
{
    return capacity_;
}

template <typename Type_>
void vector_t<Type_>::push_back(Type_ value)
{
	if ( capacity_ == 0)
	{
		capacity_ = 1;
		size_ = 1;
		data_ = new Type_ [capacity_];
		data_[size_ - 1] = value;
	}
	else if ( capacity_ == size_ )
	{
		vector_t copy( *this );
		delete [] data_;
		capacity_ = 2 * capacity_;
		data_ = new Type_ [capacity_];
		for ( std::size_t i = 0;i < size_;i++ )
		{
			this->data_[i]=copy.data_[i];
		}
		size_++;		
		data_[size_ - 1] = value;
	}
	else
	{
		size_++;
		data_[size_ - 1] = value;
	}
}

template <typename Type_>
void vector_t<Type_>::pop_back()
{
	if (size_ == 0)
	{
		std::cout << "массив пуст";
		return ;
	}
	if ( (size_- 1) <= (capacity_ / 4) )
	{
		vector_t copy( *this );
		delete [] data_;
		capacity_ = capacity_ / 2;
		data_ = new Type_ [capacity_];
		for ( std::size_t i = 0;i < size_;i++ )
		{
			this->data_[i]=copy.data_[i];
		}
		size_--;		
	}
	else
	{
		size_--;
	}
}

template <typename Type_>
Type_ & vector_t<Type_>::operator [](std::size_t index)
{
	return data_[index];
}

template <typename Type_>
Type_ vector_t<Type_>::operator [](std::size_t index) const
{
	return data_[index];
}

template <typename Type_>
Type_ & vector_t<Type_>::at(std::size_t index)
{
	try
	{
		if ((index>=size_()) || (index<0))
		{
			throw 0;
		}
		return data_[index];
	}
	catch(std::size_t i)
	{
		std::cout <<  "Данный индекс за пределами массива"; 
		return data_[i];
	}
}

template<typename Type_>
Type_  vector_t<Type_>::at(std::size_t index) const
{
	try
	{
		if ((index>=size_()) || (index<0))
		{
			throw 0;
		}
		return data_[index];
	}
	catch(std::size_t i)
	{
		std::cout <<  "Данный индекс за пределами массива"; 
		return data_[i];
	}
    	
}

template <typename Type_>
bool operator !=(vector_t<Type_> const & lhs, vector_t<Type_> const & rhs)
{
	if ( lhs == rhs )
	{
		return false;
	}
	else
	{
		return true;
	}
}
