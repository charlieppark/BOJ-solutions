class Stack:
    top_index = -1
    elements = list()
        
    def push(self, element):
        self.elements.append(element)
        self.top_index += 1
        return
    
    def pop(self):
        if self.empty(): return -1
        
        self.top_index -= 1
        return self.elements.pop(self.top_index + 1)

    def size(self):
        return self.top_index + 1

    def empty(self):
        return int(self.top_index == -1)

    def top(self):
        if self.empty(): return -1
        return self.elements[self.top_index]