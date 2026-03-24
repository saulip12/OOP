class Stats:
    @staticmethod
    def sum(a):
        total = 0
        for x in a:
            total += x
        return total
    
    @staticmethod
    def average(a):
        total = Stats.sum(a)
        return total / len(a)

def main():
    grades = [80, 75, 90, 60, 95]
    total = Stats.sum(grades)
    avg = Stats.average(grades)
    print("Sum:", total)
    print("Average:", avg)
if __name__ == "__main__":
    main()