// 题目的意思就是轮流投票，每次可以ban掉对方一人，最后哪边还有人哪边赢。
// 不难想对每个选手来讲，肯定是禁用他以后最近的对面阵营的人（前提是这个人是没被ban过的状态）

// 队列写法：
// 用两个队列记录每个l,r的下标，每次从队头取出一个，比较他们的下标，下标小的那个就可以ban掉下标大的那个。
// 下标大的那个就需要重新加入队列，但是要加上n，因为下一轮才会轮到他。

// 计数模拟写法：
// 直观的想法肯定不是先开两个队列，而是对每个元素，依次删除他后面的第一个对方阵营的元素。但是这样是O(n²),也许可以用并查集...
// 但是很麻烦。不如反过来，对每个元素，看前面有多少对方阵营的元素，这样就知道每个元素有没有被ban。

// 队列写法：
func predictPartyVictory(senate string) string {
    n, r, d := len(senate), []int{}, []int{}
    for i, v := range senate {
        if v == 'R' {
            r = append(r, i)
        } else {
            d = append(d, i)
        }
    }

    for len(r) > 0 && len(d) > 0 {
        frr, frd := r[0], d[0]
        r = r[1:]
        d = d[1:]
        if frr < frd {
            r = append(r, frr + n)
        } else {
            d = append(d, frd + n)
        }
    }

    if len(r) > 0 {
        return "Radiant"
    }
    return "Dire"
}


// 计数模拟法：
func predictPartyVictory(senateStr string) string {
	// R = true表示本轮循环结束后，字符串里依然有R。D同理
	R, D := true, true
	// flag表示R的个数，如果大于0，说明R在D前出现，R可以消灭D。如果小于0，说明D在R前出现，D可以消灭R
	flag := 0

	senate := []byte(senateStr)
	for R && D { // 一旦R或者D为false，就结束循环，说明本轮结束后只剩下R或者D了
		R = false
		D = false
		for i := 0; i < len(senate); i++ {
			if senate[i] == 'R' {
				if flag < 0  {
					 senate[i] = 0  // 消灭R，R此时为false
				} else {
					R = true // 如果没被消灭，本轮循环结束有R
				}
				flag++;
			}
			if (senate[i] == 'D') {
				if flag > 0 {
					senate[i] = 0
				} else  {
					D = true
				}
				flag--
			}
		}
	}
	// 循环结束之后，R和D只能有一个为true
	if R {
		return "Radiant"
	}
	return "Dire";
}

// 示例 1：
// 输入：senate = "RD"
// 输出："Radiant"
// 解释：
// 第 1 轮时，第一个参议员来自 Radiant 阵营，他可以使用第一项权利让第二个参议员失去所有权利。
// 这一轮中，第二个参议员将会被跳过，因为他的权利被禁止了。
// 第 2 轮时，第一个参议员可以宣布胜利，因为他是唯一一个有投票权的人。


// 示例 2：
// 输入：senate = "RDD"
// 输出："Dire"
// 解释：
// 第 1 轮时，第一个来自 Radiant 阵营的参议员可以使用第一项权利禁止第二个参议员的权利。
// 这一轮中，第二个来自 Dire 阵营的参议员会将被跳过，因为他的权利被禁止了。
// 这一轮中，第三个来自 Dire 阵营的参议员可以使用他的第一项权利禁止第一个参议员的权利。
// 因此在第二轮只剩下第三个参议员拥有投票的权利,于是他可以宣布胜利