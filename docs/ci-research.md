# CI Pipeline Research 

## Candidate Tools
- GitHub Actions
- GitLab CI
- Jenkins

## Selected Approach
GitHub Actions is preferred because it is integrated with GitHub and easy to maintain with YAML workflows.

## Planned CI Steps
- Checkout repository
- Configure build environment (Ubuntu runner)
- Build C++ project via CMake
- (Later) run tests and/or container-based checks

## Notes
The initial CI workflow file will be added in later phases when the build skeleton is ready.
Implemented in Week 2: .github/workflows/docker-build.yml builds and pushes images.
