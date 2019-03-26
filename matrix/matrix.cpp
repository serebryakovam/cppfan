#include "matrix.h"

Matrix::Matrix(const size_t height, const size_t width)
{
    data_.resize(height);
    for (size_t y = 0; y < height; y++)
    {
        data_[y].resize(width);
        for (size_t x = 0; x < width; x++)
        {
            data_[y][x] = 0;
        }
    }
}

size_t Matrix::GetHeight() const
{
    return data_.size();
}

size_t Matrix::GetWidth() const
{
    if (data_.size())
    {
        return data_[0].size();
    }
    else
    {
        return 0;
    }
}

int Matrix::GetValue(const size_t height_index, const size_t width_index) const
{
    return data_[height_index][width_index];
}

void Matrix::SetValue(const size_t height_index, const size_t width_index, const int value)
{
    data_[height_index][width_index] = value;
}

std::istream& operator >> (std::istream& input_stream, Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            int temp_int = 0;
            input_stream >> temp_int;
            matrix.SetValue(y, x, temp_int);
        }
    }

    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            output_stream << matrix.GetValue(y, x) << ' ';
        }
        output_stream << '\n';
    }

    return output_stream;
}

Matrix Matrix::Transpose() const
{
    Matrix tran(GetHeight(), GetWidth());
    for (size_t y = 0; y < GetHeight(); y++)
    {
        for (size_t x = 0; x < GetWidth(); x++)
        {
            tran.SetValue(y, x, GetValue(x, y));
        }
    }
    return tran;
}

Matrix Matrix:: operator*(const Matrix& rhs)
{
    Matrix result(GetHeight(), rhs.GetWidth());
    for (size_t y = 0; y < result.GetHeight(); y++)
    {
        for (size_t x = 0; x < result.GetWidth(); x++)
        {
            for (size_t z = 0; z < GetWidth(); z++)
            {
                result.SetValue(y, x, result.GetValue(y, x) + GetValue(y, z)*rhs.GetValue(z, x));
            }
        }
    }

    return result;
}
