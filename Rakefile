namespace :compile do
  
  desc 'compiles all sourcefiles'
  task :all do
    
    Dir[File.expand_path(File.join(File.dirname(__FILE__),'src','*.pas'))].each do |pascal_source|
      compiled_name = File.basename(pascal_source, ".pas")
      cmd = "fpc #{pascal_source} -obuild/#{compiled_name}"
      system(cmd)
    end
  end
end