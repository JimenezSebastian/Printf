int ft_process_char(va_list args)
{
	char c;
	int i;
	
	i = 0;
	c = (char)va_arg(args, int);
	write (1 , &c, 1);
	return (i);
}

int ft_process_str(va_list args)
{
	char *str;
	int i;
	
	i = 0;
	str = va_arg(args , char *);
	while (str[i])
	{
		write(1 , str[i], 1);
		++i;
	}
	return(i);
}

int ft_process_ptr(args)
{
	char char_array = 123456789abcdef
	unsigned long long addr;
	void *ptr;
	char buffer[20];
	int i;
	
	i = 0;
	shift = (sizeof(void *) * 8) - 4;
	ptr = va_arg(args , void *);
	addr = ptr;
	buffer[0] = '0';
	buffer[1] = 'x';
	
}



int process_int(va_list args)
{
	int num;
	int i;

	num = arg(args, int);
	i = ft_putnbr(num);
	return (i);
}

int ft_putnbr(int num)
{
	if (num = -2147483648)
	{
		write(1, "-2147483648", 11);
	}	
	if (num < 0)
	{
		write(1, '-', 1);
		num = -num;
	}
	if (num > 9)
		ft_putnbr(num /= 10);
	write (1, (num % 10 + 48), 1);
{

int ft_process_hex(va_list args)
{
	int i;
	int hex;
	static char hex_chars[] "0123456789abcdef";

	i = 0;
	hex = va_arg(args, int );
}


int ft_process_format(const char *format, va_list args)
{
	if (format == 'c')
		ft_process_char(args);
	if (format == 's')
		ft_process_str(args);
	if (format == 'p')
		ft_process_ptr(args);
	if (format == 'd')
		ft_process_dec(args);
	if (format == 'i')
		ft_process_dec(args);
	if (format == 'u')
		ft_process_
	if (format == 'x')
		ft_process_low_hex(args);
	if (format == 'X')
		ft_process_up_hex(args);
	if (format == '%')
		write()
	return (i);
}

int ft_the_real_printf(const char *format, va_list args)
{
	static int i = 0;
	
	while (*format)
        {
		if (format == '%')
		{
			format++;
			i += ft_process_format(args);
		}
        }
	return(i);
}

int ft_printf(const char *format, ...)
{
	int i;
	va_list args;
	va_start(args, format);

	if (!format)
		return (0);
	i = ft_the_real_printf(const char *format, va_list args);
	return (i);
}

int main()
{
	
}
