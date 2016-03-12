# clearing :on

notification :terminal_notifier

# guard :rake, task: 'compile' do
#   watch(%r{^ext/.*})
# end

guard :rake, task: "default" do
  watch(%r{^ext/.*})
  watch(%r{^spec/(.*)_spec\.rb$})
  # watch(%r{^lib/(.+)\.rb$})         { |m| "spec/#{m[1]}_spec.rb" }
  watch(%r{^lib/(.*)$})         { 'spec' }
  watch(%r{^spec/spec_helper\.rb$}) { 'spec' }
end
