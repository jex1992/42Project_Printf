/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealtypes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 13:46:07 by sjang             #+#    #+#             */
/*   Updated: 2016/10/29 13:46:09 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int      ft_dealtypes_di(t_specifies *specifies, va_list ap, char **str)
{
    if (specifies->type == 'd' || specifies->type == 'i')
    {
        if (specifies->length == 0)
            *str = ft_mknbr_longlong((long long)va_arg(ap, int));
        else if (specifies->length == 'H')
            *str = ft_mknbr_longlong((long long)((char)va_arg(ap, int)));
        else if (specifies->length == 'h')
            *str = ft_mknbr_longlong((long long)((short)va_arg(ap, int)));
        else if (specifies->length == 'l')
            *str = ft_mknbr_longlong((long long)va_arg(ap, long));
        else if (specifies->length == 'L')
            *str = ft_mknbr_longlong((long long)va_arg(ap, long long));
        else if (specifies->length == 'j')
            *str = ft_mknbr_longlong((long long)va_arg(ap, t_inxmax_t));
        else if (specifies->length == 'z')
            *str = ft_mknbr_longlong((long long)va_arg(ap, t_signed_size_t));
    }
    if (*str)
        return (1);
    return (0);
}

static int      ft_dealtypes_capd(t_specifies *specifies, va_list ap,
                                    char **str)
{
    if (specifies->type == 'D')
    {
        if (specifies->length == 0 || specifies->length == 'l' ||
            specifies->length == 'H' || specifies->length == 'h')
            *str = ft_mknbr_longlong((long long)va_arg(ap, long));
        else if (specifies->length == 'L')
            *str = ft_mknbr_longlong((long long)va_arg(ap, long long));
        else if (specifies->length == 'j')
            *str = ft_mknbr_longlong((long long)va_arg(ap, t_inxmax_t));
        else if (specifies->length == 'z')
            *str = ft_mknbr_longlong((long long)va_arg(ap, t_signed_size_t));
    }
    if (*str)
        return (1);
    return (0);
}

static int      ft_dealtypes_uoxx(t_specifies *specifies, va_list ap,
                                    char **str)
{
    int base;

    base = ft_dealtypes_getbase(specifies);
    if (specifies->length == 0)
        *str = ft_itoa_base_prtf((size_t)va_arg(ap, unsigned int)
                                , base, specifies->type - 'x' + 'a');
    else if (specifies->length == 'H')
        *str = ft_itoa_base_prtf((size_t)((unsigned char)va_arg(ap, int))
                                , base, specifies->type - 'x' + 'a');
    else if (specifies->length == 'h')
        *str = ft_itoa_base_prtf((size_t)((unsigned short)va_arg(ap, int))
                                , base, specifies->type - 'x' + 'a');
    else if (specifies->length == 'l')
        *str = ft_itoa_base_prtf((size_t)va_arg(ap, unsigned long)
                                , base, specifies->type - 'x' + 'a');
    else if (specifies->length == 'L')
        *str = ft_itoa_base_prtf((size_t)va_arg(ap, unsigned long long)
                                , base, specifies->type - 'x' + 'a');
    else if (specifies->length == 'j')
        *str = ft_itoa_base_prtf((size_t)va_arg(ap, t_uintmax_t)
                                , base, specifies->type - 'x' + 'a');
    else if (specifies->length == 'z')
        *str = ft_itoa_base_prtf((size_t)va_arg(ap, size_t)
                                , base, specifies->type - 'x' + 'a');
    return (1);
}

static int      ft_dealtypes_capou(t_specifies *specifies, va_list ap,
                                    char **str)
{
    int base;

    base = ft_dealtypes_getbase(specifies);
    if (specifies->type == 'O' || specifies->type == 'U')
    {
        if (specifies->length == 0 || specifies->length == 'l' ||
                specifies->length == 'H' || specifies->length == 'h')
            *str = ft_itoa_base_prtf((size_t)va_arg(ap, unsigned long)
                                    , base, specifies->type - 'x' + 'a');
        else if (specifies->length == 'L')
            *str = ft_itoa_base_prtf((size_t)va_arg(ap, unsigned long long)
                                    , base, specifies->type - 'x' + 'a');
        else if (specifies->length == 'j')
            *str = ft_itoa_base_prtf((size_t)va_arg(ap, t_uintmax_t)
                                    , base, specifies->type - 'x' + 'a');
        else if (specifies->length == 'z')
            *str = ft_itoa_base_prtf((size_t)va_arg(ap, size_t)
                                    , base, specifies->type - 'x' + 'a');
    }
    if (*str)
        return (1);
    return (0);
}

int             ft_dealtypes(t_specifies *specifies, va_list ap, char **str)
{
    if (specifies->type == 'd' || specifies->type == 'i')
        ft_dealtypes_di(specifies, ap, str);
    else if (specifies->type == 'D')
        ft_dealtypes_capd(specifies, ap, str);
    else if (specifies->type == 'x' || specifies->type == 'X' ||
            specifies->type == 'u' || specifies->type == 'o')
        ft_dealtypes_uoxx(specifies, ap, str);
    else if (specifies->type == 'O' || specifies->type == 'U')
        ft_dealtypes_capou(specifies, ap, str);
    else if (specifies->type == 'p' || specifies->type == 's' ||
            specifies->type == 'c')
        ft_dealtypes_psc(specifies, ap, str);
    else
        ft_dealtypes_special(specifies, str);
    ft_dealminus(specifies, str);
    if (*str)
        return (1);
    return (0);
}
