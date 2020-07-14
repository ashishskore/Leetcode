func isValid(s string) bool {
    stack := make([]byte, len(s))
    
    j := 0
    for i := 0; i < len(s); i++ {
        if isLeft(s[i]) {
            stack[j] = s[i]
            j += 1
            continue
        }
        if j < 1 {
            return false
        }
        if isPair(stack[j-1], s[i]) {
            j -= 1
        } else {
            return false
        }
    }
    return j == 0
}

func isLeft(c byte) bool {
    if c == '(' || c == '[' || c == '{' {
        return true
    }
    return false
}

func isPair(cl, cr byte) bool {
    if cl == '(' && cr == ')' {
        return true
    }
    if cl == '[' && cr == ']' {
        return true
    }

    if cl == '{' && cr == '}' {
        return true
    }
    return false
}
