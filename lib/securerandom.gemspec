Gem::Specification.new do |spec|
  spec.name          = "securerandom"
  spec.version       = "0.2.1"
  spec.authors       = ["Tanaka Akira"]
  spec.email         = ["akr@fsij.org"]

  spec.summary       = %q{Interface for secure random number generator.}
  spec.description   = %q{Interface for secure random number generator.}
  spec.homepage      = "https://github.com/ruby/securerandom"
  spec.required_ruby_version = Gem::Requirement.new(">= 2.6.0")
  spec.licenses      = ["Ruby", "BSD-2-Clause"]

  spec.metadata["homepage_uri"] = spec.homepage
  spec.metadata["source_code_uri"] = spec.homepage

  spec.files         = Dir.chdir(File.expand_path('..', __FILE__)) do
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  end
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib"]
end
