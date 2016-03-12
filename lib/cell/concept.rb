module Cell
  class Concept
    include Collection
    extend Collection::ClassMethods

    def show
      # foo = "foo"
      # bar = "bar"
      # foo + bar
      "foobar"
    end

    def self.collection(count)
      cell = new
      Array.new(count).map do ||
        cell.show
      end.join
    end
  end
end
