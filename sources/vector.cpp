#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	data_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

vector_t::vector_t(vector_t const & other)
{
	data_ = new int [other.capacity_];
	for ( std::size_t i = 0;i < other.size_; i++ ) 
	{
		data_[i] = other.data_[i];
	}
	size_ = other.size_;
	capacity_ = other.capacity_;
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if  (this != &other)
	{
		if ( data_ != nullptr )
		{
			delete [] data_;
		}
		data_ = new int [other.capacity_];
		for ( std::size_t i = 0;i < other.size_;i++ ) 
		{
			data_[i] = other.data_[i];
		}
		size_ = other.size_;
		capacity_ = other.capacity_;
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
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

vector_t::~vector_t()
{
	if ( data_ != nullptr )
	{
		delete [] data_;	
	}
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	if ( capacity_ == 0)
	{
		capacity_ = 1;
		size_ = 1;
		data_ = new int [capacity_];
		data_[size_ - 1] = value;
	}
	else if ( capacity_ == size_ )
	{
		vector_t copy( *this );
		delete [] data_;
		capacity_ = 2 * capacity_;
		data_ = new int [capacity_];
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

void vector_t::pop_back()
{
	if ( size_ <= capacity_ / 4 )
	{
		vector_t copy( *this );
		delete [] data_;
		capacity_ = capacity_ / 2;
		data_ = new int [capacity_];
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

int & vector_t::operator [](std::size_t index)
{
	return data_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return data_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	if ( (lhs.size() == rhs.size()) && (lhs.capacity() == rhs.capacity()) )
	{
		for ( std::size_t i = 0;i < lhs.size(); i++ )
		{
			if ( !( lhs[i] == rhs[i] ) )
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}
